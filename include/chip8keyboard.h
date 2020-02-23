#ifndef CHIP8KEYBOARD_H
#define CHIP8KEYBOARD_H

#include <stdbool.h>
#include "config.h"
struct chip8_keyboard
{
    bool keyboard[CHIP8_TOTAL_KEYS];
};

int chip8_keyboard_map(const char* map, char key);
void chip8_keyboard_down(struct chip8_keyboard* keyboard, int key);
void chip8_keyboard_up(struct chip8_keyboard* keyboard, int key);
bool chip8_keyboard_is_down(struct chip8_keyboard* keyboard, int key);

#endif