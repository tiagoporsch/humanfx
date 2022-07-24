#include "humanfx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void example_wave(uint32_t color) {
	device_acquire();
	send_animation_config_play(0);

	send_zone_select(1, 1, ZONE_LEFT);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, ZONE_MIDDLE_LEFT);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, ZONE_MIDDLE_RIGHT);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, ZONE_RIGHT);
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

	send_zone_select(1, 1, ZONE_LEFT);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, ZONE_MIDDLE_LEFT);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);

	send_zone_select(1, 1, ZONE_MIDDLE_RIGHT);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_zone_select(1, 1, ZONE_RIGHT);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, color);
	send_add_action(ACTION_MORPH, 500, 64, 0);
	send_add_action(ACTION_MORPH, 500, 64, 0);

	send_animation_config_play(0);
	device_release();
}

void example_spectrum(uint16_t duration) {
	device_acquire();
	send_animation_config_start(0);
	send_zone_select(1, 4, ZONE_ALL);
	send_add_action(ACTION_MORPH, duration, 64, 0xFF0000);
	send_add_action(ACTION_MORPH, duration, 64, 0xFFa500);
	send_add_action(ACTION_MORPH, duration, 64, 0xFFFF00);
	send_add_action(ACTION_MORPH, duration, 64, 0x008000);
	send_add_action(ACTION_MORPH, duration, 64, 0x00BFFF);
	send_add_action(ACTION_MORPH, duration, 64, 0x0000FF);
	send_add_action(ACTION_MORPH, duration, 64, 0x800080);
	send_animation_config_play(0);
	device_release();
}

void example_static(uint32_t color) {
	device_acquire();
	send_animation_config_start(0);
	send_zone_select(1, 4, ZONE_ALL);
	send_add_action(ACTION_COLOR, 1, 2, color);
	send_animation_config_play(0);
	device_release();
}

void example_breathe(uint16_t duration, uint32_t color) {
	device_acquire();
	send_animation_config_start(0);
	send_zone_select(1, 4, ZONE_ALL);
	send_add_action(ACTION_MORPH, duration, 64, color);
	send_add_action(ACTION_MORPH, duration, 64, 0);
	send_animation_config_play(0);
	device_release();
}

void print_usage(void) {
	printf("Usage: humanfx [command] [arguments]...\n");
	printf("Alienware 187c:0550 controller\n");
	printf("\n");
	printf("  brightness <value>\tSets the keyboard brightness\n");
	printf("\n");
}

int main(int argc, char** argv) {
	device_open();

	if (argc > 2) {
		if (!strcmp(argv[1], "brightness")) {
			uint8_t value = 100 - atoi(argv[2]);
			device_acquire();
			send_set_brightness(value, 4, ZONE_ALL);
			device_release();
		} else {
			print_usage();
		}
	} else {
		print_usage();
	}

	// Example temporary effects
	// example_wave(0xFFFFFF);
	// example_back_and_forth(0xFFFFFF);
	// example_spectrum(1000);
	// example_static(0xFF00FF);
	// example_breathe(2500, 0xFFFFFF);

	// Example setting as default
	// device_acquire();
	// send_animation_remove(1);
	// send_animation_config_start(1);
	// send_zone_select(1, 4, ZONE_ALL);
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
	// send_set_brightness(BRIGHTNESS_FULL, 4, ZONE_ALL);
	// device_release();

	device_close();
	return 0;
}