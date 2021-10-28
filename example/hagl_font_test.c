/*

MIT No Attribution

Copyright (c) 2021 Christophe Petit

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-cut-

SPDX-License-Identifier: MIT-0

*/

#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "hagl_hal.h"
#include "hagl.h"
#include "font8x13.h"
#include "font10x20.h"
#include "unscii-8-fantasy.h"

int main()
{
    color_t color1 = hagl_color(128, 255, 255);
    color_t color2 = hagl_color(255, 128, 255);
    color_t color3 = hagl_color(255, 255, 128);
    uint16_t x, y;
    clock_t start, end;
    double time_spent;
    size_t bytes;

    wchar_t *text = L"The Quick Brown Fox Jumps Over The Lazy Dog 0123456789 Times!";

    hagl_init();
    start = clock();

    hagl_draw_rectangle(4, 4, 32, 32, color1);
    hagl_draw_rectangle(100 + 4, 4, 100 + 33, 33, color2);
    hagl_draw_rectangle(200 + 4, 4, 200 + 34, 34, color3);

    x = (DISPLAY_WIDTH  / 2) - wcslen(text) * 8 / 2;
    y = (DISPLAY_HEIGHT / 2) - 13 * 4;
    hagl_draw_rectangle(x - 2, y - 2, x + wcslen(text) * 8 + 2, y + 13 + 2, color1);
    hagl_put_text(text, x, y, color1, X11_fontx2_font8x13_fnt);

    x = (DISPLAY_WIDTH  / 2) - wcslen(text) * 10 / 2;
    y = (DISPLAY_HEIGHT / 2) - 20 / 2;
    hagl_draw_rectangle(x - 2, y - 2, x + wcslen(text) * 10 + 2, y + 20 + 2, color2);
    hagl_put_text(text, x, y, color2, X11_fontx2_font10x20_fnt);

    x = (DISPLAY_WIDTH  / 2) - wcslen(text) * 8 / 2;
    y = (DISPLAY_HEIGHT / 2) + 8 * 4;
    hagl_draw_rectangle(x - 2, y - 2, x + wcslen(text) * 8 + 2, y + 8 + 2, color3);
    hagl_put_text(text, x, y, color3, fontx_unscii_8_fantasy_fnt);

    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    bytes = hagl_flush();
    printf("%dx%dx%d\n", DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_DEPTH);
    printf("\nGenerated %zu bytes in %g seconds.\n\n", bytes, time_spent);
    hagl_close();

    return 0;
}
