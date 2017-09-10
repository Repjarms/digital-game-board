PROJECT_NAME     := ble_app_template_pca10040_s132
TARGETS          := nrf52832_xxaa
OUTPUT_DIRECTORY := _build

SDK_ROOT := ../../../../../..
PROJ_DIR := ../../..

$(OUTPUT_DIRECTORY)/nrf52832_xxaa.out: \
  LINKER_SCRIPT  := ble_app_template_gcc_nrf52.ld

# Source files common to all targets
SRC_FILES += $(SDK_ROOT)/components/libraries/experimental_log/src/nrf_log_backend_rtt.c
SRC_FILES += $(SDK_ROOT)/components/libraries/experimental_log/src/nrf_log_backend_serial.c
SRC_FILES += $(SDK_ROOT)/components/libraries/experimental_log/src/nrf_log_backend_uart.c
SRC_FILES += $(SDK_ROOT)/components/libraries/experimental_log/src/nrf_log_default_backends.c
SRC_FILES += $(SDK_ROOT)/components/libraries/experimental_log/src/nrf_log_frontend.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/experimental_log/src/nrf_log_str_formatter.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/button/app_button.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/util/app_error.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/util/app_error_weak.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/scheduler/app_scheduler.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/timer/app_timer_freertos.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/source/croutine.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/source/event_groups.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/source/portable/MemMang/heap_1.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/source/list.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/portable/GCC/nrf52/port.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52/port_cmsis.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52/port_cmsis_systick.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/source/queue.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/source/tasks.c 
SRC_FILES += $(SDK_ROOT)/external/freertos/source/timers.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/util/app_util_platform.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/crc16/crc16.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/fds/fds.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/hardfault/hardfault_implementation.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/util/nrf_assert.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/atomic_fifo/nrf_atfifo.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c 
SRC_FILES += $(SDK_ROOT)/external/fprintf/nrf_fprintf.c 
SRC_FILES += $(SDK_ROOT)/external/fprintf/nrf_fprintf_format.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/fstorage/nrf_fstorage.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/fstorage/nrf_fstorage_sd.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/experimental_memobj/nrf_memobj.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/pwr_mgmt/nrf_pwr_mgmt.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/experimental_section_vars/nrf_section_iter.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/util/sdk_mapped_flags.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/sensorsim/sensorsim.c 
SRC_FILES += $(SDK_ROOT)/components/boards/boards.c 
SRC_FILES += $(SDK_ROOT)/components/drivers_nrf/clock/nrf_drv_clock.c 
SRC_FILES += $(SDK_ROOT)/components/drivers_nrf/common/nrf_drv_common.c 
SRC_FILES += $(SDK_ROOT)/components/drivers_nrf/gpiote/nrf_drv_gpiote.c 
SRC_FILES += $(SDK_ROOT)/components/drivers_nrf/uart/nrf_drv_uart.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/bsp/bsp.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/bsp/bsp_btn_ble.c 
SRC_FILES += $(SDK_ROOT)/components/drivers_nrf/twi_master/nrf_drv_twi.c 
SRC_FILES += $(SDK_ROOT)/components/drivers_nrf/uart/nrf_drv_uart.c 
SRC_FILES += $(SDK_ROOT)/components/libraries/bsp/bsp_nfc.c 
SRC_FILES += $(PROJ_DIR)/piece_ctrl.c 
SRC_FILES += $(PROJ_DIR)/location.c 
SRC_FILES += $(PROJ_DIR)/twi.c 
SRC_FILES += $(PROJ_DIR)/main.c 
# don't compile the standard SEGGER RTT sources if we are using systemview
ifeq ($(USE_SYSVIEW), )
SRC_FILES += $(SDK_ROOT)/external/segger_rtt/RTT_Syscalls_GCC.c 
SRC_FILES += $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT.c 
SRC_FILES += $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_printf.c 
endif
SRC_FILES += $(SDK_ROOT)/components/ble/common/ble_advdata.c 
SRC_FILES += $(SDK_ROOT)/components/ble/ble_advertising/ble_advertising.c 
SRC_FILES += $(SDK_ROOT)/components/ble/common/ble_conn_params.c 
SRC_FILES += $(SDK_ROOT)/components/ble/common/ble_conn_state.c 
SRC_FILES += $(SDK_ROOT)/components/ble/common/ble_srv_common.c
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/gatt_cache_manager.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/gatts_cache_manager.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/id_manager.c 
SRC_FILES += $(SDK_ROOT)/components/ble/nrf_ble_gatt/nrf_ble_gatt.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/peer_data_storage.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/peer_database.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/peer_id.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/peer_manager.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/pm_buffer.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/pm_mutex.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/security_dispatcher.c 
SRC_FILES += $(SDK_ROOT)/components/ble/peer_manager/security_manager.c 
SRC_FILES += $(SDK_ROOT)/components/toolchain/gcc/gcc_startup_nrf52.S 
SRC_FILES += $(SDK_ROOT)/components/toolchain/system_nrf52.c 
SRC_FILES += $(SDK_ROOT)/components/softdevice/common/nrf_sdh.c 
SRC_FILES += $(SDK_ROOT)/components/softdevice/common/nrf_sdh_ble.c 
SRC_FILES += $(SDK_ROOT)/components/softdevice/common/nrf_sdh_soc.c 
SRC_FILES += $(SDK_ROOT)/components/softdevice/common/nrf_sdh_freertos.c 
# if we are using systemview we want to compile sysviews freertos
ifeq ($(USE_SYSVIEW), 1)
SRC_FILES += $(PROJ_DIR)/systemview/SEGGER_SYSVIEW_FreeRTOS.c 
endif

# Include folders common to all targets
INC_FOLDERS += ../config 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/comp 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/twi_master 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/experimental_cli 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/twi_master 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_ancs_c 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_ias_c 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/pwm 
INC_FOLDERS += $(SDK_ROOT)/components/softdevice/s132/headers/nrf52 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/class/cdc/acm 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/class/hid/generic 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/class/msc 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/class/hid 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_lbs 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_gls 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/fstorage 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/i2s 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/mutex 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/gpiote 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/experimental_log/src 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/gpiote 
INC_FOLDERS += $(SDK_ROOT)/components/boards 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/experimental_memobj 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/common 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_advertising 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_bas_c 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_hrs_c 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/queue 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/pwr_mgmt 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_dtm 
INC_FOLDERS += $(SDK_ROOT)/components/toolchain/cmsis/include 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_rscs_c 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/uart 
INC_FOLDERS += $(SDK_ROOT)/components/ble/common 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_lls 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/wdt 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/bsp 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_bas 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/experimental_section_vars 
INC_FOLDERS += $(SDK_ROOT)/components/softdevice/s132/headers 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_ans_c 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/slip 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/mem_manager 
INC_FOLDERS += $(SDK_ROOT)/external/freertos/portable/GCC/nrf52 
INC_FOLDERS += $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52 
INC_FOLDERS += $(SDK_ROOT)/external/freertos/config 
INC_FOLDERS += $(SDK_ROOT)/external/freertos/source/include 
INC_FOLDERS += $(SDK_ROOT)/external/segger_rtt 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/class/cdc 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/hal 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_nus_c 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/rtc 
INC_FOLDERS += $(SDK_ROOT)/components/softdevice/common 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_ias 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/class/hid/mouse 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/ecc 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/ppi 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_dfu 
INC_FOLDERS += $(SDK_ROOT)/external/fprintf 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/twis_slave 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/atomic 
INC_FOLDERS += $(SDK_ROOT)/components 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/scheduler 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/experimental_log 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_hts 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/delay 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/crc16 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/timer 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/util 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/pwm 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/csense_drv 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/csense 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/balloc 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/low_power_pwm 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/hardfault 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_cscs 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/uart 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/hci 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/class/hid/kbd 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/spi_slave 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/lpcomp 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/timer 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/rng 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/power 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/config 
INC_FOLDERS += $(SDK_ROOT)/components/toolchain 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/led_softblink 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/qdec 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_cts_c 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/spi_master 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_nus 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_hids 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/strerror 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/pdm 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/crc32 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd/class/audio 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/sensorsim 
INC_FOLDERS += $(SDK_ROOT)/components/ble/peer_manager 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/swi 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_tps 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_dis 
INC_FOLDERS += $(SDK_ROOT)/components/device 
INC_FOLDERS += $(SDK_ROOT)/components/ble/nrf_ble_gatt 
INC_FOLDERS += $(SDK_ROOT)/components/ble/nrf_ble_qwr 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/button 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/usbd 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/saadc 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/atomic_fifo 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_lbs_c 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_racp 
INC_FOLDERS += $(SDK_ROOT)/components/toolchain/gcc 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/fds 
INC_FOLDERS += $(SDK_ROOT)/components/libraries/twi 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/clock 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_rscs 
INC_FOLDERS += $(SDK_ROOT)/components/drivers_nrf/usbd 
INC_FOLDERS += $(SDK_ROOT)/components/ble/ble_services/ble_hrs 
# if we are using systemview we want to include the systemview headers
ifeq ($(USE_SYSVIEW), 1)
INC_FOLDERS += $(PROJ_DIR)/systemview 
endif

# Libraries common to all targets
ifeq ($(USE_SYSVIEW), 1)
LIB_FILES += $(PROJ_DIR)/systemview/SysviewSoftdevice_S132V2.a 
endif

# Optimization flags
OPT = -O3 -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)
CFLAGS += -DBOARD_PCA10040
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DNRF52
CFLAGS += -DNRF52832_XXAA
CFLAGS += -DNRF52_PAN_74
CFLAGS += -DNRF_SD_BLE_API_VERSION=5
CFLAGS += -DS132
CFLAGS += -DSOFTDEVICE_PRESENT
CFLAGS += -DSWI_DISABLE0
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS +=  -Wall -Werror
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums 
# we only want to use systemview in development mode
ifeq ($(USE_SYSVIEW), 1)
	CFLAGS += -DNRF_LOG_USES_SYSVIEW=1
endif

# C++ flags common to all targets
CXXFLAGS += $(OPT)

# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DBOARD_PCA10040
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DNRF52
ASMFLAGS += -DNRF52832_XXAA
ASMFLAGS += -DNRF52_PAN_74
ASMFLAGS += -DNRF_SD_BLE_API_VERSION=5
ASMFLAGS += -DS132
ASMFLAGS += -DSOFTDEVICE_PRESENT
ASMFLAGS += -DSWI_DISABLE0

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L $(TEMPLATE_PATH) -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs


# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys -lm


.PHONY: default help

# Default target - first one defined
default: nrf52832_xxaa

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo 	nrf52832_xxaa

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc

include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

.PHONY: flash flash_softdevice erase

# Flash the program
flash: $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex
	@echo Flashing: $<
	nrfjprog -f nrf52 --program $< --sectorerase
	nrfjprog -f nrf52 --reset

# Flash softdevice
flash_softdevice:
	@echo Flashing: s132_nrf52_5.0.0_softdevice.hex
	nrfjprog -f nrf52 --program $(SDK_ROOT)/components/softdevice/s132/hex/s132_nrf52_5.0.0_softdevice.hex --sectorerase
	nrfjprog -f nrf52 --reset

erase:
	nrfjprog -f nrf52 --eraseall
