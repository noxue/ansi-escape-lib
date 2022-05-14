#include "../ansi.h"
#include <stdio.h>
#include <stdlib.h>
#include "imgs.h"
#include <string.h>

#define show_img(img)                                                    \
    do                                                                   \
    {                                                                    \
        for (int i = 0; i < sizeof(img) / sizeof(img[0]); i++)           \
        {                                                                \
            for (int j = 0; j < sizeof(img[0]) / sizeof(img[0][0]); j++) \
            {                                                            \
                int *color = img[i][j];                                  \
                ansi_fg_rgb(color[0], color[1], color[2]);               \
                ansi_font_reverse();                                     \
                printf("  ");                                            \
            }                                                            \
            printf("\n");                                                \
        }                                                                \
    } while (0)

int main(int argc, char const *argv[])
{

    // 获取命令行参数
    if (argc < 2)
    {
        printf("Usage: %s <img_name> [flash]\n", argv[0]);
        printf("<img_name>:alipay, wx, android, huawei, linux, waner, wangzhe, weibo, win9, win11, windows, wx\n");
        return 0;
    }
// 如果是windows平台
#ifdef _WIN32
    system("cls"); // 如果不清屏，ansi可能会不起作用
#else              // linux
    system("clear");
#endif
    ansi_reset();
    ansi_font_bold();

    // 如果设置了flash
    if (argc == 3 && strcmp(argv[2], "flash") == 0)
    {
        ansi_font_flash();
    }

    const char *img = argv[1];
    // 比较字符串

    if (!strcmp(img, "alipay"))
    {
        show_img(img_alipay);
    }
    else if (!strcmp(img, "wx"))
    {
        show_img(img_wx);
    }
    else if (!strcmp(img, "android"))
    {
        show_img(img_android);
    }
    else if (!strcmp(img, "huawei"))
    {
        show_img(img_huawei);
    }
    else if (!strcmp(img, "linux"))
    {
        show_img(img_linux);
    }
    else if (!strcmp(img, "waner"))
    {
        show_img(img_waner);
    }
    else if (!strcmp(img, "wangzhe"))
    {
        show_img(img_wangzhe);
    }
    else if (!strcmp(img, "weibo"))
    {
        show_img(img_weibo);
    }
    else if (!strcmp(img, "win9"))
    {
        show_img(img_win9);
    }
    else if (!strcmp(img, "win11"))
    {
        show_img(img_win11);
    }
    else if (!strcmp(img, "windows"))
    {
        show_img(img_windows);
    }
    else if (!strcmp(img, "wx"))
    {
        show_img(img_wx);
    }
    else
    {
        printf("No such image: %s\n", img);
    }

    ansi_font_no_flash();
    ansi_reset();
    return 0;
}