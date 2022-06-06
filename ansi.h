#include <stdarg.h>
#include <stdio.h>

#ifndef __ANSI_H__
#define __ANSI_H__

typedef struct
{
    const char *black;   // 用法: ansi(Ansi.fg.black);
    const char *red;     // 用法: ansi(Ansi.fg.red);
    const char *green;   // 用法: ansi(Ansi.fg.green);
    const char *yellow;  // 用法：ansi(Ansi.fg.yellow);
    const char *blue;    // 用法: ansi(Ansi.fg.blue);
    const char *magenta; // 用法：ansi(Ansi.fg.magenta);
    const char *cyan;    // 用法: ansi(Ansi.fg.cyan);
    const char *white;   // 用法: ansi(Ansi.fg.white);
    const char *rgb;     // 用法： ansi(Ansi.fg.rgb, 255, 0, 0);
    const char *default_color;
} _color_t;

typedef struct
{
    const char *bold;             // 用法: ansi(Ansi.bold);
    const char *dim;              // 用法: ansi(Ansi.dim);
    const char *italic;           // 用法: ansi(Ansi.italic);
    const char *underline;        // 用法: ansi(Ansi.underline);
    const char *flash;            // 用法: ansi(Ansi.flash);
    const char *flash_fast;       // 用法: ansi(Ansi.flash_fast);
    const char *reverse;          // 用法: ansi(Ansi.reverse);
    const char *invisible;        // 用法: ansi(Ansi.invisible);
    const char *strikethrough;    // 用法: ansi(Ansi.strikethrough);
    const char *normal;           // 用法: ansi(Ansi.normal);
    const char *alt_1;            // 用法: ansi(Ansi.alt_1);
    const char *alt_2;            // 用法: ansi(Ansi.alt_2);
    const char *alt_3;            // 用法: ansi(Ansi.alt_3);
    const char *alt_4;            // 用法: ansi(Ansi.alt_4);
    const char *alt_5;            // 用法: ansi(Ansi.alt_5);
    const char *alt_6;            // 用法: ansi(Ansi.alt_6);
    const char *alt_7;            // 用法: ansi(Ansi.alt_7);
    const char *alt_8;            // 用法: ansi(Ansi.alt_8);
    const char *alt_9;            // 用法: ansi(Ansi.alt_9);
    const char *alt_10;           // 用法: ansi(Ansi.alt_10);
    const char *underline_double; // 用法: ansi(Ansi.underline_double);
    const char *bold_off;         // 用法: ansi(Ansi.bold_off);
    const char *italic_off;       // 用法: ansi(Ansi.italic_off);
    const char *underline_off;    // 用法: ansi(Ansi.underline_off);
    const char *no_flash;         // 用法: ansi(Ansi.no_flash);
    const char *no_reverse;       // 用法: ansi(Ansi.no_reverse);
    const char *visible;          // 用法: ansi(Ansi.visible);
    const char *no_strikethrough; // 用法: ansi(Ansi.no_strikethrough);
} _font_t;

typedef struct
{

    const char *up;          // 用法: ansi(Ansi.cursor.up, 1);
    const char *down;        // 用法: ansi(Ansi.cursor.down, 1);
    const char *forward;     // 用法: ansi(Ansi.cursor.forward, 1);
    const char *backward;    // 用法: ansi(Ansi.cursor.backward, 1);
    const char *next_line;   // 用法: ansi(Ansi.cursor.next_line, 1);
    const char *prev_line;   // 用法: ansi(Ansi.cursor.prev_line,  1);
    const char *position;    // 用法: ansi(Ansi.cursor.position, 5, 3);
    const char *save;        // 用法: ansi(Ansi.cursor.save);
    const char *restore;     // 用法: ansi(Ansi.cursor.restore);
    const char *hide;        // 用法: ansi(Ansi.cursor.hide);
    const char *show;        // 用法: ansi(Ansi.cursor.show);
    const char *scroll_up;   // 用法: ansi(Ansi.cursor.scroll_up, 1);
    const char *scroll_down; // 用法: ansi(Ansi.cursor.scroll_down, 1);
} _cursor_t;

typedef struct
{
    const char *reset;
    const char *clear;      // 用法: ansi(Ansi.clear,2) ;
    const char *clear_line; // 用法: ansi(Ansi.hide);
    _color_t fg;
    _color_t bg;
    _font_t font;
    _cursor_t cursor;
} _ansi;

extern const _ansi Ansi;

#ifdef __cplusplus
// C++
extern "C"
{
#endif

    // 工具函数，方便组装 ANSI 字符串，并输出到标准输出
    void ansi(const char *fmt, ...);

    // 初始化,执行清屏
    void ansi_init();

    // 重置所有设置
    void ansi_reset();

    // 清屏，光标位置不变
    void ansi_clear();

    // 清除光标到屏幕开头
    void ansi_clear_to_start();

    // 清除光标到屏幕末尾
    void ansi_clear_to_end();

    // 清除整行
    void ansi_clear_line();

    // 清除光标到行首
    void ansi_clear_to_line_start();

    // 清除光标到行尾
    void ansi_clear_to_line_end();

    //=======操作光标=====================

    // 光标上移一行
    void ansi_cursor_up();

    // 光标下一一行
    void ansi_cursor_down();

    // 光标向右一列
    void ansi_cursor_forward();

    // 光标向左一列
    void ansi_cursor_backward();

    // 光标向前移动n列
    void ansi_cursor_forward_n(int n);

    // 光标向后移动n列
    void ansi_cursor_backward_n(int n);

    // 光标向下移动n行
    void ansi_cursor_down_n(int n);

    // 光标向上移动n行
    void ansi_cursor_up_n(int n);

    // 光标移动到指定行列
    void ansi_cursor_position(int row, int col);

    // 保存光标位置
    void ansi_cursor_save();

    // 恢复光标位置
    void ansi_cursor_restore();

    // 隐藏光标
    void ansi_cursor_hide();

    // 显示光标
    void ansi_cursor_show();

    //==========设置前景色==========

    // 设置前景色为红色
    void ansi_fg_red();

    // 设置前景色为绿色
    void ansi_fg_green();

    // 设置前景色为黄色
    void ansi_fg_yellow();

    // 设置前景色为蓝色
    void ansi_fg_blue();

    // 设置前景色为品红色
    void ansi_fg_magenta();

    // 设置前景色为青色
    void ansi_fg_cyan();

    // 设置前景色为白色
    void ansi_fg_white();

    // 恢复默认颜色
    void ansi_fg_default();

    // 设置背景色为指定rgb颜色
    void ansi_fg_rgb(int r, int g, int b);

    //=======设置背景色=====

    // 设置背景色为红色
    void ansi_bg_red();

    // 设置背景色为绿色
    void ansi_bg_green();

    // 设置背景色为黄色
    void ansi_bg_yellow();

    // 设置背景色为蓝色
    void ansi_bg_blue();

    // 设置背景色为品红色
    void ansi_bg_magenta();

    // 设置背景色为青色
    void ansi_bg_cyan();

    // 设置背景色为白色
    void ansi_bg_white();

    //  恢复默认颜色
    void ansi_bg_default();

    // 设置背景色为指定rgb颜色
    void ansi_bg_rgb(int r, int g, int b);

    //=====字体======

    // 字体加粗
    void ansi_font_bold();

    // 字体倾斜
    void ansi_font_italic();

    // 字体下划线
    void ansi_font_underline();

    // 字体闪烁
    void ansi_font_flash();

    // 字体快速闪烁,不全不支持，大多数时候和ansi_font_flash效果一样
    void ansi_font_flash_fast();

    // 字体颜色和背景颜色反转
    void ansi_font_reverse();

    // 隐藏内容
    void ansi_font_invisible();

    // 删除线
    void ansi_font_strikethrough();

    // 恢复默认字体
    void ansi_font_normal();

    // 可选字体,没啥效果
    void ansi_font_alt_1();

    void ansi_font_alt_2();

    void ansi_font_alt_3();

    void ansi_font_alt_4();

    void ansi_font_alt_5();

    void ansi_font_alt_6();

    void ansi_font_alt_7();

    void ansi_font_alt_8();

    void ansi_font_alt_9();

    void ansi_font_alt_10();

    // 双下划线
    void ansi_font_underline_double();

    // 取消加粗
    void ansi_font_bold_off();

    // 取消斜体
    void ansi_font_italic_off();

    // 取消下划线
    void ansi_font_underline_off();

    // 取消闪烁
    void ansi_font_no_flash();

    // 取消颜色和背景颜色反转
    void ansi_font_no_reverse();

    // 显示内容
    void ansi_font_visible();

    // 取消删除线
    void ansi_font_no_strikethrough();

#ifdef __cplusplus
}
#endif
#endif
