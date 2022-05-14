/**
 * @file 2048.c
 * @brief 2048 game
 * 根据 https://github.com/noxue/game2048 改编，仅仅修改了控制台显示效果和添加方向键控制游戏，其他没做任何修改
 * 运行环境 windows gcc
 */

/*2048*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "../ansi.h"

int code[4][4] = {0, 0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 0}; /*游戏中的16个格子*/
int temp[5];                   /*中间变量*/
int move = 0;                  /*移动次数*/
int score = 0;                 /*分数*/

// 2048颜色，前景色和背景色 十六进制表示
int colors[12][6] = {
    {0x77, 0x6e, 0x65, 0xee, 0xe4, 0xda},
    {0x77, 0x6e, 0x65, 0xed, 0xe0, 0xc8},
    {0xf9, 0xf6, 0xf2, 0xf2, 0xb1, 0x79},
    {0xf9, 0xf6, 0xf2, 0xf2, 0xcc, 0x66},
    {0xf9, 0xf6, 0xf2, 0xf6, 0x7c, 0x5f},
    {0xf9, 0xf6, 0xf2, 0xf6, 0x5e, 0x3b},
    {0xf9, 0xf6, 0xf2, 0xed, 0xcf, 0x72},
    {0xf9, 0xf6, 0xf2, 0xed, 0xcc, 0x61},
    {0xf9, 0xf6, 0xf2, 0xed, 0xc8, 0x50},
    {0xf9, 0xf6, 0xf2, 0xed, 0xc5, 0x3f},
    {0xf9, 0xf6, 0xf2, 0xed, 0xc2, 0x2e},
    {205, 192, 180, 205, 192, 180},
};

// 根据数字获取颜色
int *get_colors(int num)
{
    switch (num)
    {
    case 2:
        return colors[0];
    case 4:
        return colors[1];
    case 8:

        return colors[2];
    case 16:
        return colors[3];
    case 32:
        return colors[4];
    case 64:

        return colors[5];
    case 128:
        return colors[6];
    case 256:
        return colors[7];
    case 512:
        return colors[8];
    case 1024:
        return colors[9];
    case 2048:
        return colors[10];
    default:
        // 返回默认背景色
        return colors[11];
    }
}

void print(void) /*显示游戏界面*/
{
    int i, j;

    // ansi_clear(); // 清屏会有闪烁
    ansi_cursor_position(2, 20);
    ansi_font_flash();
    ansi_fg_rgb(0xf9, 0xf6, 0xf2);
    printf("2048 game");
    ansi_font_no_flash();
    ansi_reset();
    ansi_cursor_position(7, 4);
    printf("W/UP");
    ansi_cursor_position(8, 4);
    printf("A/LEFT");
    ansi_cursor_position(9, 4);
    printf("S/DOWN");
    ansi_cursor_position(10, 4);
    printf("D/RIGHT");
    ansi_cursor_position(11, 4);
    ansi_fg_red();
    printf("Q/EXIT");
    ansi_reset();

    ansi_cursor_position(5, 40);
    printf("Score:%d", score, move);
    ansi_cursor_position(6, 40);
    printf("Move:%d", move);
    ansi_cursor_position(17, 12);
    ansi_font_underline();
    printf("author: Yanjisheng and noxue\n");

    ansi_reset();
    ansi_cursor_hide();

    // 定义游戏左上角xy坐标
    const int base_row = 3;
    const int base_col = 13;
    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            ansi_fg_rgb(255, 255, 255);
            ansi_cursor_position(base_row + i * 3 + 1, base_col + j * 6 + 1);
            int *color = get_colors(code[i][j]);
            if (code[i][j] == 0)
            {
                // 默认背景色，数组第11个元素
                ansi_bg_rgb(color[3], color[4], color[5]);
                printf("      ");
                ansi_cursor_position(base_row + i * 3 + 2, base_col + j * 6 + 1);
                printf("      ");
                ansi_cursor_position(base_row + i * 3 + 3, base_col + j * 6 + 1);
                printf("      ");
                ansi_reset();
            }
            else
            {
                ansi_fg_rgb(color[0], color[1], color[2]);
                ansi_bg_rgb(color[3], color[4], color[5]);
                printf("      ");
                ansi_cursor_position(base_row + i * 3 + 2, base_col + j * 6 + 1);
                printf(" %4d ", code[i][j]);
                ansi_cursor_position(base_row + i * 3 + 3, base_col + j * 6 + 1);
                printf("      ");
                ansi_reset();
            }
        }
    }
    ansi_reset();
}

int add(void) /*对中间变量数组进行处理*/
{
    int i;
    int t = 0;
    int change = 0; /*判断数组是否有改变，0不变，1变化*/

    do
    {
        for (i = 0; i <= 3; i++)
        {
            if (temp[i] == 0)
            {
                if (temp[i] != temp[i + 1])
                    change = 1; /*当一个0后面不是0时数组改变*/
                temp[i] = temp[i + 1];
                temp[i + 1] = 0;
            }
        } /*去掉中间的0*/
        t++;
    } while (t <= 3); /*重复多次*/
    for (i = 1; i <= 3; i++)
    {
        if (temp[i] == temp[i - 1])
        {

            if (temp[i] != 0)
            {
                change = 1;              /*当两个非零相同的数相加时数组改变*/
                score = score + temp[i]; /*加分*/
            }
            temp[i - 1] = temp[i - 1] * 2;
            temp[i] = 0;
        }
    } /*把两个相邻的相同的数加起来*/
    do
    {
        for (i = 0; i <= 3; i++)
        {
            if (temp[i] == 0)
            {
                temp[i] = temp[i + 1];
                temp[i + 1] = 0;
            }
        } /*去掉中间的0*/
        t++;
    } while (t <= 3); /*重复多次*/
    return change;
}

int main(void)
{
    int gameover = 0; /*判断游戏是否结束，1结束，0继续*/
    int i, j;
    int change = 1; /*判断格子中的数是否改变，0不变*/
    char input;

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    srand((unsigned)time(NULL)); /*设置随机数的起点*/
    while (gameover == 0)
    {
        if (change >= 1) /*仅当数发生改变时添加新数*/
        {
            do
            {
                i = ((unsigned)rand()) % 4;
                j = ((unsigned)rand()) % 4;
            } while (code[i][j] != 0);
            if (((unsigned)rand()) % 4 == 0)
            {
                code[i][j] = 4;
            }
            else
            {
                code[i][j] = 2; /*随机选一个空格填上2或4*/
            }
            move++; /*增加次数*/
        }
        print();         /*显示*/
        input = getch(); /*输入方向*/

        change = 0;
        switch (input)
        {
        case 'q': /*退出*/
        case 'Q':
            ansi_cursor_position(20, 0);
            printf("Are you sure to exit?(y/n)");
            input = getchar();
            if (input == 'y' || input == 'Y')
                exit(0);
            break;

        case 'W':
        case 'w': /*上*/
        case 72:
            for (j = 0; j <= 3; j++)
            {
                for (i = 0; i <= 3; i++)
                {
                    temp[i] = code[i][j]; /*把一列数移到中间变量*/
                }
                temp[4] = 0;
                change = change + add();
                for (i = 0; i <= 3; i++)
                {
                    code[i][j] = temp[i]; /*把处理好的中间变量移回来*/
                }
            }
            break;

        case 'A':
        case 'a': /*左*/
        case 75:  // 方向键左
            for (i = 0; i <= 3; i++)
            {
                for (j = 0; j <= 3; j++)
                {
                    temp[j] = code[i][j]; /*把一行数移到中间变量*/
                }
                temp[4] = 0;
                change = change + add();
                for (j = 0; j <= 3; j++)
                {
                    code[i][j] = temp[j]; /*把处理好的中间变量移回来*/
                }
            }

            break;

        case 'S':
        case 's': /*下*/
        case 80:  // 方向键下
            for (j = 0; j <= 3; j++)
            {
                for (i = 0; i <= 3; i++)
                {
                    temp[i] = code[3 - i][j]; /*把一列数移到中间变量*/
                }
                temp[4] = 0;
                change = change + add();
                for (i = 0; i <= 3; i++)
                {
                    code[3 - i][j] = temp[i]; /*把处理好的中间变量移回来*/
                }
            }
            break;

        case 'D':
        case 'd': /*右*/
        case 77:  // 方向键右
            for (i = 0; i <= 3; i++)
            {
                for (j = 0; j <= 3; j++)
                {
                    temp[j] = code[i][3 - j]; /*把一行数移到中间变量*/
                }
                temp[4] = 0;
                change = change + add();
                for (j = 0; j <= 3; j++)
                {
                    code[i][3 - j] = temp[j]; /*把处理好的中间变量移回来*/
                }
            }
            break;
        }
        gameover = 1;
        for (i = 0; i <= 3; i++)
            for (j = 0; j <= 3; j++)
                if (code[i][j] == 0)
                    gameover = 0; /*所有格子都填满则游戏结束*/
    }
    printf("Game over!\n");
    getch();
    return 0;
}