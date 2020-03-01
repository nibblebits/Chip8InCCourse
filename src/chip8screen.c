#include "chip8screen.h"
#include <assert.h>
#include <memory.h>


static void chip8_screen_check_bounds(int x, int y)
{
    assert(x >= 0 && x < CHIP8_WIDTH && y >= 0 && y < CHIP8_HEIGHT);
}

void chip8_screen_set(struct chip8_screen* screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    screen->pixels[y][x] = true;
}


void chip8_screen_clear(struct chip8_screen* screen)
{
    memset(screen->pixels, 0, sizeof(screen->pixels));
}

bool chip8_screen_is_set(struct chip8_screen* screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    return screen->pixels[y][x];
}

bool chip8_screen_draw_sprite(struct chip8_screen* screen, int x, int y, const char* sprite, int num)
{
    bool pixel_collison = false;

    for (int ly = 0; ly < num; ly++)
    {
        char c = sprite[ly];
        for (int lx = 0; lx < 8; lx++)
        {
            if ((c & (0b10000000 >> lx)) == 0)
                continue;
            
            if (screen->pixels[(ly+y) % CHIP8_HEIGHT][(lx+x) % CHIP8_WIDTH])
            {
                pixel_collison = true;
            }

            screen->pixels[(ly+y) % CHIP8_HEIGHT][(lx+x) % CHIP8_WIDTH] ^= true;
        }
    }
    return pixel_collison;
}