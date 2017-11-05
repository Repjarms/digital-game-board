/* Source file for Location BLE service */

#include <string.h>
#include <stdbool.h>
#include "sdk_common.h"
#include "location.h"
#include "ble_srv_common.h"

#include "nrf_log.h"
#include "piece_ctrl.h"

#define INVALID_LOCATION 255

/**@brief Function for handling connect event
 *
 * @param[in]   p_loc       location service struct
 * @param[in]   p_ble_evt   Event received from the BLE stack
 */
static void on_connect(ble_loc_t * p_loc, ble_evt_t const * p_ble_evt)
{
  p_loc->conn_handle = p_ble_evt->evt.gap_evt.conn_handle;
}

/**@brief Function for handling the Disconnect event.
 *
 * @param[in]   p_loc       Location service struct
 * @param[in]   p_ble_evt   Event received from the BLE stack
 */
static void on_disconnect(ble_loc_t * p_loc, ble_evt_t const * p_ble_evt)
{
  UNUSED_PARAMETER(p_ble_evt);
  p_loc->conn_handle = BLE_CONN_HANDLE_INVALID;
}

/**@brief Function for handling the Write event
 *
 * @param[in]   p_loc       Location service struct
 * @param[in]   p_ble_evt   Event received from the BLE stack.
 */
static void on_write(ble_loc_t * p_loc, ble_evt_t const * p_ble_evt)
{
  if (!p_loc->is_notification_supported)
  {
    return;
  }

  ble_gatts_evt_write_t const * p_evt_write = &p_ble_evt->evt.gatts_evt.params.write;

  if ( (p_evt_write->handle == p_loc->loc_handles.cccd_handle)
      && (p_evt_write->len == 2) )
  {
    if (p_loc->evt_handler == NULL)
    {
      return;
    }

    ble_loc_evt_t evt;

    if (ble_srv_is_notification_enabled(p_evt_write->data))
    {
      evt.evt_type = BLE_LOC_EVT_NOTIFICATION_ENABLED;
    }
    else
    {
      evt.evt_type = BLE_LOC_EVT_NOTIFICATION_DISABLED;
    }

    // CCCD written, call application event handler
    p_loc->evt_handler(p_loc, &evt);
  }
}

/**@brief Main event handler for the service. Routes events to specific
 * handlers within a switch statement
 */
void ble_loc_on_ble_evt(ble_evt_t const * p_ble_evt, void * p_context)
{
  if ((p_context == NULL) || (p_ble_evt == NULL))
  {
    return;
  }

  NRF_LOG_INFO("%d\n", p_ble_evt);

  ble_loc_t * p_loc = (ble_loc_t *)p_context;

  switch (p_ble_evt->header.evt_id)
  {
    case BLE_GAP_EVT_CONNECTED: // connect event
      on_connect(p_loc, p_ble_evt); // call connect handler
      break;

    case BLE_GAP_EVT_DISCONNECTED: // disconnect event
      on_disconnect(p_loc, p_ble_evt); // call disconnect handler
      break;

    case BLE_GATTS_EVT_WRITE: // write event
      on_write(p_loc, p_ble_evt); // call write handler
      break;

    default:
      break;
  }
}

/**@brief Function for adding the Location characteristic
 *
 * @param[in]     p_loc       Location Service struct
 * @param[in]     p_loc_init  Service init information
 *
 * @return        NRF_SUCCESS on success, otherwise an error code
 */
static uint32_t location_char_add(ble_loc_t * p_loc, const ble_loc_init_t * p_loc_init)
{
  uint32_t            err_code;
  ble_gatts_char_md_t char_md;
  ble_gatts_attr_md_t cccd_md;
  ble_gatts_attr_t    attr_char_value;
  ble_uuid_t          ble_uuid;
  ble_gatts_attr_md_t attr_md;
  piece_t *           initial_loc; 
  uint8_t             encoded_report_ref[BLE_SRV_ENCODED_REPORT_REF_LEN];
  uint8_t             init_len; 

  // Add Location characteristic
  if (p_loc->is_notification_supported)
  {
    memset(&cccd_md, 0, sizeof(cccd_md));

    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.read_perm);
    cccd_md.write_perm = p_loc_init->loc_char_attr_md.cccd_write_perm;
    cccd_md.vloc = BLE_GATTS_VLOC_STACK;
  }

  memset(&char_md, 0, sizeof(char_md));

  char_md.char_props.read   = 1;
  char_md.char_props.notify = (p_loc->is_notification_supported) ? 1 : 0;
  char_md.p_char_user_desc  = NULL;
  char_md.p_char_pf         = NULL;
  char_md.p_user_desc_md    = NULL;
  char_md.p_cccd_md         = (p_loc->is_notification_supported) ? &cccd_md : NULL;
  char_md.p_sccd_md         = NULL;

  BLE_UUID_BLE_ASSIGN(ble_uuid, BLE_UUID_LOCATION_CHAR);

  memset(&attr_md, 0, sizeof(attr_md));

  ble_gap_conn_sec_mode_t perm_test;
  BLE_GAP_CONN_SEC_MODE_SET_OPEN(&perm_test);

  attr_md.read_perm   = perm_test; //p_loc_init->loc_char_attr_md.read_perm;
  attr_md.write_perm  = perm_test; //p_loc_init->loc_char_attr_md.write_perm;
  attr_md.vloc        = BLE_GATTS_VLOC_STACK;
  attr_md.rd_auth     = 0;
  attr_md.wr_auth     = 0;
  attr_md.vlen        = 0;

  // initialize initial location
  initial_loc = get_current_location();

  memset(&attr_char_value, 0, sizeof(attr_char_value));

  attr_char_value.p_uuid    = &ble_uuid;
  attr_char_value.p_attr_md = &attr_md;
  attr_char_value.init_len  = sizeof(initial_loc[0]) * 6; 
  attr_char_value.init_offs = 0;
  attr_char_value.max_len   = sizeof(initial_loc[0]) * 6; 
  attr_char_value.p_value   = (uint8_t *)initial_loc;

  // Add the service
  err_code = sd_ble_gatts_characteristic_add(p_loc->service_handle, &char_md, &attr_char_value, &p_loc->loc_handles);

  if (err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("%0x", err_code);
    return err_code;
  }

  if (p_loc_init->p_report_ref != NULL)
  {
    BLE_UUID_BLE_ASSIGN(ble_uuid, BLE_UUID_REPORT_REF_DESCR);

    memset(&attr_md, 0, sizeof(attr_md)); 

    attr_md.read_perm = p_loc_init->loc_report_read_perm;
    BLE_GAP_CONN_SEC_MODE_SET_NO_ACCESS(&attr_md.write_perm);


    attr_md.vloc    = BLE_GATTS_VLOC_STACK;
    attr_md.rd_auth = 0;
    attr_md.wr_auth = 0;
    attr_md.vlen    = 0;

    init_len = ble_srv_report_ref_encode(encoded_report_ref, p_loc_init->p_report_ref);

    memset(&attr_char_value, 0, sizeof(attr_char_value));

    attr_char_value.p_uuid    = &ble_uuid;
    attr_char_value.p_attr_md = &attr_md;
    attr_char_value.init_len  = init_len;
    attr_char_value.init_offs = 0;
    attr_char_value.max_len   = attr_char_value.init_len;
    attr_char_value.p_value   = encoded_report_ref;

    err_code = sd_ble_gatts_descriptor_add(p_loc->loc_handles.value_handle, &attr_char_value, &p_loc->report_ref_handle);

    if (err_code != NRF_SUCCESS)
    {
      return err_code;
    }
  }
  else
  {
    p_loc->report_ref_handle = BLE_GATT_HANDLE_INVALID;
  }

  return NRF_SUCCESS;
}

uint32_t ble_loc_init(ble_loc_t * p_loc, const ble_loc_init_t * p_loc_init)
{
  if (p_loc == NULL || p_loc_init == NULL)
  {
    return NRF_ERROR_NULL;
  }


  uint32_t    err_code;
  ble_uuid_t  ble_uuid;

  // Initialize service structure
  p_loc->evt_handler               = p_loc_init->evt_handler;
  p_loc->conn_handle               = BLE_CONN_HANDLE_INVALID;
  p_loc->is_notification_supported = p_loc_init->support_notification;
  p_loc->location_last             = NULL;

  // Add service
  BLE_UUID_BLE_ASSIGN(ble_uuid, BLE_UUID_LOCATION_CHAR);

  err_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY, &ble_uuid, &p_loc->service_handle);

  if (err_code != NRF_SUCCESS)
  {
    return err_code;
  }

  return location_char_add(p_loc, p_loc_init);
}

uint32_t ble_loc_location_update(ble_loc_t * p_loc, piece_t * location)
{
  bool hasLocChanged = false; 
  uint8_t locArrSize = 5;

  if (p_loc == NULL)
  {
    return NRF_ERROR_NULL;
  }

  // check if any piece location has changed
  for (int i=0; i<locArrSize; i++)
  {
    if (location[i].x_coord != p_loc->location_last[i].x_coord)
    {
      hasLocChanged = true;
      break;
    }
    else if (location[i].y_coord != p_loc->location_last[i].y_coord)
    {
      hasLocChanged = true;
      break;
    }
  }

  uint32_t err_code = NRF_SUCCESS;
  ble_gatts_value_t gatts_value;

  if (hasLocChanged == true)
  {
    // Initialize value struct
    memset(&gatts_value, 0, sizeof(gatts_value));

    gatts_value.len     = sizeof(location[0]) * 6;
    gatts_value.offset  = 0;
    gatts_value.p_value = (uint8_t *)location;

    // Update database
    err_code = sd_ble_gatts_value_set(p_loc->conn_handle, p_loc->loc_handles.value_handle, &gatts_value);

    if (err_code == NRF_SUCCESS)
    {
      // Save new location value
      for (int i=0; i<locArrSize; i++)
      {
        p_loc->location_last[i].x_coord = location[i].x_coord;
        p_loc->location_last[i].y_coord = location[i].y_coord;
      }      
    }
    else
    {
      return err_code;
    }

    // Send value if connected and notifying
    if ((p_loc->conn_handle != BLE_CONN_HANDLE_INVALID) && p_loc->is_notification_supported)
    {
      ble_gatts_hvx_params_t hvx_params;

      memset(&hvx_params, 0, sizeof(hvx_params));

      hvx_params.handle = p_loc->loc_handles.value_handle;
      hvx_params.type   = BLE_GATT_HVX_NOTIFICATION;
      hvx_params.offset = gatts_value.offset;
      hvx_params.p_len  = &gatts_value.len;
      hvx_params.p_data = gatts_value.p_value;

      err_code = sd_ble_gatts_hvx(p_loc->conn_handle, &hvx_params);
    }
    else
    {
      err_code = NRF_ERROR_INVALID_STATE;
    }
  }

  return err_code;
}
