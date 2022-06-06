#include <stdio.h>
#include <stdlib.h>
#include "ansi.h"

const _ansi Ansi = {
    "\x1b[0m",
    "\x1b[%dJ", // 清除屏幕的部分区域。如果 n 是 0（或缺失），则清除从光标位置到屏幕末尾的部分。如果 n 是 1，则清除从光标位置到屏幕开头的部分。如果 n 是 2，则清除整个屏幕（在 DOS ANSI.SYS 中，光标还会向左上方移动）。如果 n 是 3，则清除整个屏幕，并删除回滚缓存区中的所有行（这个特性是 [[xterm]] 添加的，其他终端应用程序也支持）。
    "\x1b[%dK", // 清除行内的部分区域。如果 n 是 0（或缺失），清除从光标位置到该行末尾的部分。如果 n 是 1，清除从光标位置到该行开头的部分。如果 n 是 2，清除整行。光标位置不变。
    {
        "\x1b[30m",
        "\x1b[31m",
        "\x1b[32m",
        "\x1b[33m",
        "\x1b[34m",
        "\x1b[35m",
        "\x1b[36m",
        "\x1b[37m",
        "\x1b[38;2;%d;%d;%dm",
        "\x1b[39m",
    },
    {
        "\x1b[40m",
        "\x1b[41m",
        "\x1b[42m",
        "\x1b[43m",
        "\x1b[44m",
        "\x1b[45m",
        "\x1b[46m",
        "\x1b[47m",
        "\x1b[48;2;%d;%d;%dm",
        "\x1b[49m",
    },
    {
        "\x1b[1m",
        "\x1b[2m",
        "\x1b[3m",
        "\x1b[4m",
        "\x1b[5m",
        "\x1b[6m",
        "\x1b[7m",
        "\x1b[8m",
        "\x1b[9m",
        "\x1b[22m",
        "\x1b[10m",
        "\x1b[11m",
        "\x1b[12m",
        "\x1b[13m",
        "\x1b[14m",
        "\x1b[15m",
        "\x1b[16m",
        "\x1b[17m",
        "\x1b[18m",
        "\x1b[19m",
        "\x1b[21m",
        "\x1b[22m",
        "\x1b[23m",
        "\x1b[24m",
        "\x1b[25m",
        "\x1b[27m",
        "\x1b[28m",
        "\x1b[29m",
    },
    {
        "\x1b[%dA",
        "\x1b[%dB",
        "\x1b[%dC",
        "\x1b[%dD",
        "\x1b[%dE",
        "\x1b[%dF",
        "\x1b[%d;%dH",
        "\x1b[s",
        "\x1b[u",
        "\x1b[?25l",
        "\x1b[?25h",
        "\x1b[%dS",
        "\x1b[%dT",
    },
};

// 工具函数，方便组装 ANSI 字符串，并输出到标准输出
void ansi(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

// 重置所有设置
void ansi_reset()
{
    // 如果是windows系统
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    
    ansi(Ansi.reset);
}

// 清屏，光标位置不变
void ansi_clear()
{
    ansi(Ansi.clear, 2);
}

// 清除光标到屏幕开头
void ansi_clear_to_start()
{
    ansi(Ansi.clear, 1);
}

// 清除光标到屏幕末尾
void ansi_clear_to_end()
{
    ansi(Ansi.clear, 0);
}

// 清除整行
void ansi_clear_line()
{
    ansi(Ansi.clear_line, 2);
}

// 清除光标到行首
void ansi_clear_to_line_start()
{
    ansi(Ansi.clear, 1);
}
// 清除光标到行尾
void ansi_clear_to_line_end()
{
    ansi(Ansi.clear, 0);
}

//=======操作光标=====================

// 光标上移一行
void ansi_cursor_up()
{
    ansi(Ansi.cursor.up, 1);
}

// 光标下移一行
void ansi_cursor_down()
{
    ansi(Ansi.cursor.down, 1);
}

// 光标向右一列
void ansi_cursor_forward()
{
    ansi(Ansi.cursor.forward, 1);
}

// 光标向左一列
void ansi_cursor_backward()
{
    ansi(Ansi.cursor.backward, 1);
}

// 光标向前移动n列
void ansi_cursor_forward_n(int n)
{
    ansi(Ansi.cursor.forward, n);
}

// 光标向后移动n列
void ansi_cursor_backward_n(int n)
{
    ansi(Ansi.cursor.backward, n);
}

// 光标向下移动n行
void ansi_cursor_down_n(int n)
{
    ansi(Ansi.cursor.down, n);
}

// 光标向上移动n行
void ansi_cursor_up_n(int n)
{
    ansi(Ansi.cursor.up, n);
}

void ansi_cursor_position(int row, int col)
{
    ansi(Ansi.cursor.position, row, col);
}

// 保存光标位置
void ansi_cursor_save()
{
    ansi(Ansi.cursor.save);
}

// 恢复光标位置
void ansi_cursor_restore()
{
    ansi(Ansi.cursor.restore);
}

// 隐藏光标
void ansi_cursor_hide()
{
    ansi(Ansi.cursor.hide);
}

// 显示光标
void ansi_cursor_show()
{
    ansi(Ansi.cursor.show);
}

//==========设置前景色==========

void ansi_fg_red()
{
    ansi(Ansi.fg.red);
}

void ansi_fg_green()
{
    ansi(Ansi.fg.green);
}

void ansi_fg_yellow()
{
    ansi(Ansi.fg.yellow);
}

void ansi_fg_blue()
{
    ansi(Ansi.fg.blue);
}

void ansi_fg_magenta()
{
    ansi(Ansi.fg.magenta);
}

void ansi_fg_cyan()
{
    ansi(Ansi.fg.cyan);
}

void ansi_fg_white()
{
    ansi(Ansi.fg.white);
}

// 恢复默认颜色
void ansi_fg_default()
{
    ansi(Ansi.fg.default_color);
}

// 设置背景色为指定rgb颜色
void ansi_fg_rgb(int r, int g, int b)
{
    ansi(Ansi.fg.rgb, r, g, b);
}

//=======设置背景色=====

void ansi_bg_red()
{
    ansi(Ansi.bg.red);
}

void ansi_bg_green()
{
    ansi(Ansi.bg.green);
}

void ansi_bg_yellow()
{
    ansi(Ansi.bg.yellow);
}

void ansi_bg_blue()
{
    ansi(Ansi.bg.blue);
}

void ansi_bg_magenta()
{
    ansi(Ansi.bg.magenta);
}

void ansi_bg_cyan()
{
    ansi(Ansi.bg.cyan);
}

void ansi_bg_white()
{
    ansi(Ansi.bg.white);
}

void ansi_bg_rgb(int r, int g, int b)
{
    ansi(Ansi.bg.rgb, r, g, b);
}

void ansi_bg_default()
{
    ansi(Ansi.bg.default_color);
}

//=====字体======

void ansi_font_bold()
{
    ansi(Ansi.font.bold);
}

void ansi_font_italic()
{
    ansi(Ansi.font.italic);
}

void ansi_font_underline()
{
    ansi(Ansi.font.underline);
}

void ansi_font_flash()
{
    ansi(Ansi.font.flash);
}

void ansi_font_flash_fast()
{
    ansi(Ansi.font.flash_fast);
}

void ansi_font_reverse()
{
    ansi(Ansi.font.reverse);
}

// invisible
void ansi_font_invisible()
{
    ansi(Ansi.font.invisible);
}

// strikethrough
void ansi_font_strikethrough()
{
    ansi(Ansi.font.strikethrough);
}

// normal
void ansi_font_normal()
{
    ansi(Ansi.font.normal);
}

// alt_1
void ansi_font_alt_1()
{
    ansi(Ansi.font.alt_1);
}

void ansi_font_alt_2()
{
    ansi(Ansi.font.alt_2);
}

void ansi_font_alt_3()
{
    ansi(Ansi.font.alt_3);
}

void ansi_font_alt_4()
{
    ansi(Ansi.font.alt_4);
}

void ansi_font_alt_5()
{
    ansi(Ansi.font.alt_5);
}

void ansi_font_alt_6()
{
    ansi(Ansi.font.alt_6);
}

void ansi_font_alt_7()
{
    ansi(Ansi.font.alt_7);
}

void ansi_font_alt_8()
{
    ansi(Ansi.font.alt_8);
}

void ansi_font_alt_9()
{
    ansi(Ansi.font.alt_9);
}

void ansi_font_alt_10()
{
    ansi(Ansi.font.alt_10);
}

// underline_double
void ansi_font_underline_double()
{
    ansi(Ansi.font.underline_double);
}

// bold_off
void ansi_font_bold_off()
{
    ansi(Ansi.font.bold_off);
}

// italic_off
void ansi_font_italic_off()
{
    ansi(Ansi.font.italic_off);
}

// underline_off
void ansi_font_underline_off()
{
    ansi(Ansi.font.underline_off);
}

// no_flash
void ansi_font_no_flash()
{
    ansi(Ansi.font.no_flash);
}

// no_reverse
void ansi_font_no_reverse()
{
    ansi(Ansi.font.no_reverse);
}

// visible
void ansi_font_visible()
{
    ansi(Ansi.font.visible);
}

// no_strikethrough
void ansi_font_no_strikethrough()
{
    ansi(Ansi.font.no_strikethrough);
}
