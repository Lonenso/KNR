#include <stdio.h>

#define MAXCOL 10
#define TABSTOP 4

char line[MAXCOL];

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

// 切行, 编辑器智能格式化超过80个字符
// eg: abcdefghijklmn
// => abcdefghij
//    klmn
// abcdefg   jklmn
// => abcdefg
//    jklmn
// abcdefg<tab>zxcv
// => abcdef****
//    zxcv
int main()
{
    int c, pos;
    pos = 0;

    while ((c = getchar()) != EOF)
    {
        line[pos] = c;
        if (c == '\t')
        {
            pos = exptab(pos);
        }
        else if (c == '\n')
        {
            printl(pos);
            pos = 0;
        }
        else if (++pos >= MAXCOL)
        {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}

void printl(int pos)
{
    for (int i = 0; i < pos; ++i)
    {
        putchar(line[i]);
    }
    if (pos > 0)
    {
        putchar('\n');
    }
}

int exptab(int pos)
{
    line[pos] = ' ';
    for (++pos; pos < MAXCOL && (pos % TABSTOP != 0); ++pos)
    {
        line[pos] = ' ';
    }
    if (pos < MAXCOL)
    {
        return pos;
    }
    else
    {
        printl(pos);
        return 0;
    }
}

int findblnk(int pos)
{
    // 原书写的是 line[pos] == ' ', 应该不对, 题目写的是最后一个非空格之后
    while (pos > 0 && line[pos] != ' ') 
    {
        --pos;
    }
    if (pos == 0)
    {
        return MAXCOL;
    }
    else
    {
        return pos + 1;
    }
}

int newpos(int pos)
{
    if (pos <= 0 || pos >= MAXCOL)
    {
        return 0;
    }
    else
    {
        int i = 0;
        for (int j = pos; j < MAXCOL; ++j, ++i)
        {
            line[i] = line[j];
        }
        return i;
    }
}