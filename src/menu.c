#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "keyboard.h"
#include "game.h"

static uint8_t selected = 1;
static bool in_help = false;

void menu_help(void)
{
    printf("\033[H\033[J");

    printf("===========\n");
    printf("   HELP    \n");
    printf("===========\n");
    printf("A/D - Move\n");
    printf("ENTER - Shoot\n");
    printf("R - Restart\n");
    printf("\n> EXIT\n");

    fflush(stdout);
}

void menu_text(void)
{
    printf("\033[H\033[J");

    printf("===========\n");
    printf("   SPOOM   \n");
    printf("===========\n");

    printf(selected == 1 ? " > START\n" : "   START\n");
    printf(selected == 2 ? " > HELP\n"  : "   HELP\n");
    printf(selected == 3 ? " > EXIT\n"  : "   EXIT\n");

    fflush(stdout);
}

void main_menu(uint8_t ch) {
    bool is_menu_dirty = (ch == 255);

    if (in_help) {
        if (ch == '\n') {
            in_help = false;
            is_menu_dirty = true;
        }
    } else {
        if (ch == 'w') {
            if (selected > 1) {
                selected--;
            } else {
                selected = 3;
            }
            is_menu_dirty = true;
        }

        else if (ch == 's') {
            if (selected < 3) {
                selected++;
            } else {
                selected = 1;
            }
            is_menu_dirty = true;
        }

        else if (ch == '\n') {
            if (selected == 1) {
                game_main();
                is_menu_dirty = true;
            }
            else if (selected == 2) {
                in_help = true;
                is_menu_dirty = true;
            }
            else if (selected == 3) {
                printf("\033[H\033[J");
                fflush(stdout);
                exit(0);
            }
        }
    }

    if (is_menu_dirty) {
        if (in_help) {
            menu_help();
        } else {
            menu_text();
        }
    }
}
