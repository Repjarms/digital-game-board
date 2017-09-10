#ifndef LOCATION_H_GF6CR0AG
#define LOCATION_H_GF6CR0AG

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "piece_ctrl.h"
#include "ble.h"
#include "sdk_common.h"
#include "ble_srv_common.h"
#include "nrf_sdh_ble.h"


#define BLE_UUID_LOCATION_SERVICE 0x3dd72e4dfb8d4a938d4b07c4eff1a7a7
#define BLE_UUID_LOCATION_CHAR 0xa7a7

/* Typedefs */

/**@brief Location service event type */
typedef enum
{
  BLE_LOC_EVT_NOTIFICATION_ENABLED,
  BLE_LOC_EVT_NOTIFICATION_DISABLED
} ble_loc_evt_type_t;

/**@brief Location service event */
typedef struct
{
  ble_loc_evt_type_t evt_type;
} ble_loc_evt_t;

// Forward declaration of the ble_loc_t type
typedef struct ble_loc_s ble_loc_t;

/**@brief Location service event handler type */
typedef void (*ble_loc_evt_handler_t) (ble_loc_t * p_loc, ble_loc_evt_t * p_evt);

/**@brief Location service init structure. Contains all options and data needed
 * for the initialization of the service. */
typedef struct
{
  ble_loc_evt_handler_t         evt_handler;
  bool                          support_notification;
  ble_srv_report_ref_t *        p_report_ref;
  piece_t *                     initial_loc;
  ble_srv_cccd_security_mode_t  loc_char_attr_md;
  ble_gap_conn_sec_mode_t       loc_report_read_perm;
} ble_loc_init_t;

/**@brief Location service structure. Contains status info for the service */
struct ble_loc_s
{
  ble_loc_evt_handler_t         evt_handler;
  uint16_t                      service_handle;
  ble_gatts_char_handles_t      loc_handles;
  uint16_t                      report_ref_handle;
  piece_t *                     location_last;
  uint16_t                      conn_handle;
  bool                          is_notification_supported;
};

/**@brief Function for initializing the Location service
 *
 * @param[out]  p_loc       Location service struct. Supplied by app and IDs
 * the serivce instance
 * @param[in]   p_loc_init  Info needed to initialize the service.
 *
 * @return      NRF_SUCCESS on successful initialization of the service,
 * otherwise an error code
 */
uint32_t ble_loc_init(ble_loc_t * p_loc, const ble_loc_init_t * p_loc_init);

/**@brief Function for handling the Application's BLE Stack events
 *
 * @details Handles all events from the BLE stack of interest to the Location
 * Service
 *
 * @param[in]     p_ble_evt     Event received from the BLE stack
 * @param[in]     p_context     Location Service structure
 */
void ble_bas_on_ble_evt(ble_evt_t const * p_ble_evt, void * p_context);

/**@brief Function for updating the location
 *
 * @details this is where the main logic for handling the TWI interface needs
 * to go. The function needs to loop through all available pieces, update their
 * locations, and store them in an array
 *
 * @param[in]     p_loc       Location service struct
 * @param[in]     loc         New Location value TODO: need to refactor to have
 * array 
 *
 * @return        NRF_SUCCESS   on success, otherwise an error code
 */

uint32_t ble_loc_location_update(ble_loc_t * p_loc, piece_t * location);

#endif /* end of include guard: LOCATION_H_GF6CR0AG */
