/* Source file for Piece Controller */

#include <stdio.h>
#include "app_util_platform.h"
#include "piece_ctrl.h"
#include "location.h"
#include "twi.h"

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
  piece_t piece_one   = { .x_coord = 200, .y_coord = 200, .id = 0x03 };
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

/**@brief Find the address of a piece
 *
 */
/*
static void find_piece_address(piece_t * piece)
{
  piece->id = 0x01; 
}
*/

static ret_code_t update_piece_location(piece_t * piece)
{
  ret_code_t err_code;
  err_code = read_piece_data(piece);
  APP_ERROR_CHECK(err_code); 
  NRF_LOG_INFO("Piece Data: %d\n", piece->x_coord);

  return err_code;
}

ret_code_t update_location()
{
  ret_code_t err_code;

  for (int i=0; i<PIECE_MAX; i++)
  {
    err_code = update_piece_location(&piece_arr[i]);
  }

  return NRF_SUCCESS;
}
