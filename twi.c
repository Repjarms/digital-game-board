/* TWI source file */

#include <stdio.h>
#include "boards.h"
#include "app_util_platform.h"
#include "app_error.h"
#include "nrf_drv_twi.h"
#include "nrf_delay.h"


#include "twi.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#define TWI_INSTANCE_ID    0
#define TWI_SLAVE_ADDR     0x01

/* TWI Instance */
static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);

/* Location read from slave */
static uint8_t m_location[3];
static uint8_t arr_size = sizeof(m_location) / sizeof(m_location[0]);

static volatile bool twi_xfer_done = false;

__STATIC_INLINE void data_handler(uint8_t location)
{
  NRF_LOG_INFO("Location is %d\n", location);
}

/**
 * @brief TWI event handler
 */
void twi_handler(nrf_drv_twi_evt_t const * p_event, void * p_context)
{
  switch (p_event->type)
  {
    case NRF_DRV_TWI_EVT_DONE:
      if (p_event->xfer_desc.type == NRF_DRV_TWI_XFER_RX) // if event is receive
      {
        data_handler(m_location[0]);
      }
      twi_xfer_done = true;
      break;
    default:
      break;
  }
}

/**
 * @brief UART initialization
 */
void twi_init(void)
{
  ret_code_t err_code;

  const nrf_drv_twi_config_t twi_board_config = {
    .scl                    = 3,
    .sda                    = 4,
    .frequency              = NRF_TWI_FREQ_100K,
    .interrupt_priority     = APP_IRQ_PRIORITY_LOW,
    .clear_bus_init         = false
  };

  err_code = nrf_drv_twi_init(&m_twi, &twi_board_config, twi_handler, NULL);
  APP_ERROR_CHECK(err_code);

  nrf_drv_twi_enable(&m_twi);
}

/**
 * @brief Function for reading data from temperature sensor.
 */
ret_code_t read_piece_data()
{
  NRF_LOG_INFO("Read piece location\n");
  NRF_LOG_INFO("Size of %d\n", sizeof(m_location));
  twi_xfer_done = false;

  ret_code_t err_code = nrf_drv_twi_rx(&m_twi, TWI_SLAVE_ADDR, &m_location[0], arr_size);
  APP_ERROR_CHECK(err_code);

  return err_code;
}




