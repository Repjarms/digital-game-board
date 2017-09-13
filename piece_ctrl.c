/* Source file for Piece Controller */

#include <stdio.h>
#include "app_util_platform.h"
#include "piece_ctrl.h"
#include "twi.h"

#include "FreeRTOS.h"
#include "task.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"

#define PIECE_MAX 5

/**@Notes
 *
 * This file should do the following things:
 *  - Initialize pieces
 *  - Scan for their addresses (call out to TWI.c)
 *  - Scan for their location (will have timer in main.c)
 *  - Update Location BLE service with locations (call out to location.c)
 */

piece_t piece_arr[6];

void pieces_init()
{
  /* Init first three pieces */
  piece_t piece_one   = { .x_coord = 200, .y_coord = 200, .id = 0x01 };
  piece_t piece_two   = { .x_coord = 200, .y_coord = 200, .id = 0x03 };
  piece_t piece_three = { .x_coord = 200, .y_coord = 200, .id = 0x03 };

  /* Init last three pieces */
  piece_t piece_four  = { .x_coord = 200, .y_coord = 200, .id = 0x03 };
  piece_t piece_five  = { .x_coord = 200, .y_coord = 200, .id = 0x03 };
  piece_t piece_six   = { .x_coord = 200, .y_coord = 200, .id = 0x03 };

  /* Load piece_t structs into array */
  piece_arr[0] = piece_one;
  piece_arr[1] = piece_two;
  piece_arr[2] = piece_three;
  piece_arr[3] = piece_four;
  piece_arr[4] = piece_five;
  piece_arr[5] = piece_six;
}

piece_t * get_current_location()
{
  return piece_arr;
}

void update_piece_location(uint8_t * idx, TaskHandle_t task)
{
  piece_t * piece = &piece_arr[*idx];

  ret_code_t err_code;
  err_code = read_piece_data(piece);
  APP_ERROR_CHECK(err_code); 
}
