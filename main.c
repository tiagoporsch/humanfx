#include "humanfx.h"

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

int main(void) {
	device_open();

	// Example effects
	//example_wave(0xFFFFFF);
	//example_back_and_forth(0xFFFFFF);
	//example_spectrum(0x0282, 0x000F);

	// Example of reading data from device
	//device_acquire();
	//send_request_animation_count();
	//uint8_t ret[33];
	//device_receive(ret, sizeof(ret));
	//printf("[ ");
	//for (uint16_t i = 0; i < sizeof(ret); i++)
	//	printf("%02x ", ret[i]);
	//printf("]\n");
	//device_release();

	device_close();
	return 0;
}