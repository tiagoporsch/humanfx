#include "humanfx.h"

#include <printf.h>

void example_wave(uint32_t color) {
	device_acquire();
	send_animation_config_play(0);

	send_zone_select(1, 1, (uint8_t[]) { ZONE_LEFT });
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, (uint8_t[]) { ZONE_MIDDLE_LEFT });
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, (uint8_t[]) { ZONE_MIDDLE_RIGHT });
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, (uint8_t[]) { ZONE_RIGHT });
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);

	send_animation_config_play(0);
	device_release();
}

void example_back_and_forth(uint32_t color) {
	device_acquire();
	send_animation_config_start(0);

	send_zone_select(1, 1, (uint8_t[]) { ZONE_LEFT });
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, (uint8_t[]) { ZONE_MIDDLE_LEFT });
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);

	send_zone_select(1, 1, (uint8_t[]) { ZONE_MIDDLE_RIGHT });
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, (uint8_t[]) { ZONE_RIGHT });
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_animation_config_play(0);
	device_release();
}

void example_spectrum(uint16_t duration, uint16_t tempo) {
	device_acquire();
	send_animation_config_start(0);

	send_zone_select(1, 4, (uint8_t[]) { ZONE_LEFT, ZONE_MIDDLE_LEFT, ZONE_RIGHT, ZONE_MIDDLE_RIGHT });
	send_add_action(ACTION_MORPH, duration, tempo, 0xFF0000);
	send_add_action(ACTION_MORPH, duration, tempo, 0xFFa500);
	send_add_action(ACTION_MORPH, duration, tempo, 0xFFFF00);
	send_add_action(ACTION_MORPH, duration, tempo, 0x008000);
	send_add_action(ACTION_MORPH, duration, tempo, 0x00BFFF);
	send_add_action(ACTION_MORPH, duration, tempo, 0x0000FF);
	send_add_action(ACTION_MORPH, duration, tempo, 0x800080);

	send_animation_config_play(0);
	device_release();
}

void example_static(uint32_t color) {
	device_acquire();
	send_animation_config_start(0);
	send_zone_select(1, 4, (uint8_t[]) { ZONE_LEFT, ZONE_MIDDLE_LEFT, ZONE_MIDDLE_RIGHT, ZONE_RIGHT });
	send_add_action(ACTION_COLOR, 1, 2, color);
	send_animation_config_play(0);
	device_release();
}

int main(void) {
	device_open();

	// Example temporary effects
	// example_wave(0xFFFFFF);
	// example_back_and_forth(0xFFFFFF);
	// example_spectrum(0x0282, 0x000F);
	// example_static(0xFF00FF);

	// Example setting as default
	// device_acquire();
	// send_animation_remove(1);
	// send_animation_config_start(1);
	// send_zone_select(1, 4, (uint8_t[]) { ZONE_LEFT, ZONE_MIDDLE_LEFT, ZONE_MIDDLE_RIGHT, ZONE_RIGHT });
	// send_add_action(ACTION_COLOR, 1, 2, 0xFFFFFF);
	// send_animation_config_save(1);
	// send_animation_set_default(1);
	// device_release();

	// Example of reading data from device
	// device_acquire();
	// send_request_animation_count();
	// uint8_t ret[33] = {0};
	// device_receive(ret, sizeof(ret));
	// printf("[ ");
	// for (uint16_t i = 0; i < sizeof(ret); i++)
	// 	printf("%02x ", ret[i]);
	// printf("]\n");
	// device_release();

	// Set brightness
	// device_acquire();
	// send_set_brightness(BRIGHTNESS_FULL, 4, (uint8_t[]) {0, 1, 2, 3});
	// device_release();

	device_close();
	return 0;
}