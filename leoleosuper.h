#pragma once
//#include "quantum.h"
//#include <qp.h>

//----------------------------------------------------------
// General stuff

typedef enum {
    USBPD_500MA,
    USBPD_900MA,
    USBPD_1500MA,
    USBPD_3000MA,
} usbpd_allowance_t_4;

//extern painter_device_t lcd;

void matrix_wait_for_interrupt(void);

void        usbpd_update(void);
//const char* usbpd_str(usbpd_allowance_t_4 allowance);

//----------------------------------------------------------
// Runtime data sync -- keyboard

#pragma pack(push)
#pragma pack(1)
typedef struct kb_runtime_config {
    usbpd_allowance_t_4 current_setting : 2;
} kb_runtime_config;
#pragma pack(pop)

extern kb_runtime_config kb_state;

void kb_state_update(void);
