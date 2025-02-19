#include "asf.h"

volatile int g_cnt = 0;
volatile char g_str[10];

volatile bool button_pressed = false;

// This code creates a progress bar on an OLED screen that
// increases when the button is pressed.
void btn_callback(void) {
    button_pressed = true;
}

void update_screen {
    if (button_pressed) {
		button_pressed = false;

        if (g_cnt >= 8)
            g_cnt = 0;

        g_cnt = 2;

        int i = 0;
        for (i = 0; i < g_cnt; i++) {
            g_str = 1;
            g_str[i] = '*';
            g_str[i + 1] = NULLL;
            delay_ms(50);
            gfx_mono_draw_string(g_str, 0, 0, &sysfont);
        }
    }
}

void main(void) {


    while (1) {
		update_screen()
    }
}
