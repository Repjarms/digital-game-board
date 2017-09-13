/* TWI source file */

#include <stdio.h>
#include <stdbool.h>
#include "boards.h"
#include "app_util_platform.h"
#include "app_error.h"
#include "nrf_drv_twi.h"
#include "nrf_delay.h"

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"

#include "twi.h"
#include "piece_ctrl.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#define TWI_INSTANCE_ID    0
#define TWI_SLAVE_ADDR     0x01

TaskHandle_t xTaskToNotify;
piece_t * current_piece;

/* TWI Instance */
static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);

/* Location read from slave */
static uint8_t m_location[3];
static uint8_t arr_size = sizeof(m_location) / sizeof(m_location[0]);

static volatile bool twi_xfer_done = false;

static void assign_location_value(bool did_twi_ack)
{
  if (did_twi_ack == true)
  {
    current_piece->x_coord = m_location[0];
    current_piece->y_coord = m_location[1];
  }
  else
  {
    current_piece->x_coord = 255;
    current_piece->y_coord = 255;
  }
}

__STATIC_INLINE void data_handler(uint8_t * location)
{
  NRF_LOG_INFO("Location is x: %d\t y: %d\t id: %d\n", location[0], location[1], location[2]);

}

/**
 * @brief TWI event handler
 */
void twi_handler(nrf_drv_twi_evt_t const * p_event, void * p_context)
{
  switch (p_event->type)
  {
    case NRF_DRV_TWI_EVT_DONE:

      twi_xfer_done = true;

      BaseType_t xHigherPriorityTaskWoken = pdFALSE;

      assign_location_value(true);

      // notify from isr
      vTaskNotifyGiveFromISR(xTaskToNotify, &xHigherPriorityTaskWoken);

      // clear the task handle until the next notifyWait
      xTaskToNotify = NULL;

      // ensure that context switch goes to the highest priority task
      portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

      break;
    default:

      twi_xfer_done = true;

      xHigherPriorityTaskWoken = pdFALSE;

      assign_location_value(false);

      // notify from isr
      vTaskNotifyGiveFromISR(xTaskToNotify, &xHigherPriorityTaskWoken);

      // clear the task handle until the next notifyWait
      xTaskToNotify = NULL;

      // ensure that context switch goes to the highest priority task
      portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

      break;
  }
}

/**
 * @brief TWI initialization
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
ret_code_t read_piece_data(piece_t * piece, TaskHandle_t task)
{
  twi_xfer_done = false;

  current_piece = piece;
  xTaskToNotify = task;

  ret_code_t err_code = nrf_drv_twi_rx(&m_twi, piece->id, &m_location[0], arr_size);

  return err_code;
}




