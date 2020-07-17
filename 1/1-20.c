#include <stdio.h>

#define TABSTOP 4
#define TAB "\\t"
#define SPACE "*"

// 书里的版本不容易看, 使用更明显的表示方法
void myputchar(int c)
{
    if (c == '\t')
    {
        printf("%s", TAB);
    }
    else if (c == ' ')
    {
        printf("%s", SPACE);
    }
    else
    {
        putchar(c);
    }
}

// 用空格替换tab, 跟在编辑器里tab一样
// eg:
// abcd\tefg => abcd****efg
// abc\tefg => abc*efg
int main()
{
    int c, nb, pos;

    nb = 0;
    pos = 1;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            // eg: abc\tefg => pos = 4, TABSTOP=4, nb = 1
            nb = TABSTOP - (pos - 1) % TABSTOP;
            while (nb > 0)
            {
                myputchar(' ');
                --nb;
                ++pos;
            }
        }
        else if (c == '\n')
        {
            myputchar(c);
            pos = 1;
        }
        else
        {
            myputchar(c);
            ++pos;
        }
    }
}