/* Source file for led library */

#include <stdint.h>
#include <stdbool.h>
#include "nrf.h"
#include "nrf_gpiote.h"
#include "nrf_gpio.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_gpiote.h"
#include "app_error.h"

/*
 * Led library should do the following:
 *
 * have static functions that sent GPIO commands
 * expose public functions that do general tasks such as "show range", or
 * "team capture"
 */

void board_gpio_init()
{
  ret_code_t err_code;

  if (!nrf_drv_gpiote_is_init())
  {
    err_code = nrf_drv_gpiote_init();
    UNUSED_VARIABLE(err_code);
  }
}
