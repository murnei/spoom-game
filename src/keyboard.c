#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <termios.h>

void input_init(void)
{
    struct termios t;

    tcgetattr(STDIN_FILENO, &t);

    t.c_lflag &= ~(ICANON | ECHO);
    t.c_cc[VMIN] = 0;
    t.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

uint8_t get_key(void)
{
    uint8_t c;

    if (read(STDIN_FILENO, &c, 1) == 1) {
        return c;
    }

    return 0;
}

