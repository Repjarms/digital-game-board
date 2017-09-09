#ifndef __SYSVIEW_SOFTDEVICE_H__
#define __SYSVIEW_SOFTDEVICE_H__

#include <stdint.h>
#include <stdbool.h>

/*
 * enable or disable one single irq for logging
 * 
 * eg sysview_irq_log( SysTick_IRQn, false );		// disable SysTick logging
 *    sysview_irq_log( RTC1_IRQn, true );			// enable RTC1 logging'
 *    sysview_irq_log( SVCALL_IRQn, true );			// you probably want this
 */
void sysview_irq_log(  int8_t irq_num, bool enable );

/*
 * enable or disable logging of all IRQs, equivalent to calling
 * sysview_irq_log( <irq>, enable ) 
 * for all IRQ numbers
 * 
 * default state is enabled 
 */
void sysview_all_irq_log( bool enable );

// turn on or off
// enabled = true to turn on, false to turn off
// tasks   = true to artificially group events into User/Event/Softdevice tasks, false to just output the events
void sysview_softdevice_enable( bool enabled, bool tasks );

// manual logging of in and out of idle mode
void sysview_softdevice_mark_sleep( bool sleeping );


#endif // __SYSVIEW_SOFTDEVICE_H__