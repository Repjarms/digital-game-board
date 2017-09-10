#ifndef TWI_H_1B9FEQN5
#define TWI_H_1B9FEQN5

#include <stdio.h>
#include "boards.h"
#include "app_util_platform.h"
#include "app_error.h"
#include "nrf_drv_twi.h"
#include "nrf_delay.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

void twi_init();

void twi_start_task();

ret_code_t read_piece_data();


#endif /* end of include guard: TWI_H_1B9FEQN5 */
