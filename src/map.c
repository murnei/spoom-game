#include <stdint.h>
#include <stdio.h>
#include "map.h"
#include "player.h"
#include "macro.h"

void draw_frame(uint8_t frame[HEIGHT][WIDTH]) {
    printf("\033[2J\033[H");

    for (uint8_t y = 0; y < HEIGHT; y++) {
        for (uint8_t x = 0; x < WIDTH; x++) {
            uint8_t num = frame[y][x];

            if (num == 0) {
                printf("#");
            } else if (num == 1) {
                printf(RED "@" RESET);
            } else if (num == 2) {
                printf(BLUE "^" RESET);
            }
		}
        printf("\n");
    }
}
