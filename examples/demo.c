#include <stdio.h>
#include <stdlib.h>
#include "../ansi.h"

int main(int argc, char const *argv[])
{
    system("cls");

    ansi_cursor_position(1, 1);
    ansi_bg_blue();
    printf("Hello World!");
    ansi_font_reverse();
    printf("Hello World!");
    ansi_font_no_reverse();
    printf("Hello World!");
    ansi_reset();
    ansi_font_underline_off();
    printf("Hello World!\n");
    ansi_font_underline_double();
    printf("Hello World!\n");
    ansi_font_underline_off();
    printf("Hello World!\n");
    ansi_font_underline_off();
    ansi_font_bold();
    printf("Hello World!\n");
    ansi_font_invisible();
    printf("Hello World!\n");
    ansi_font_visible();
    ansi_font_flash();
    printf("Hello World!\n");
    ansi_font_flash_fast();
    printf("Hello World!\n");
    ansi(Ansi.clear);
    printf("cccc");
    ansi_cursor_backward_n(3);
    ansi_clear_to_line_end();
    printf("d");
    ansi_reset();
    return 0;
}