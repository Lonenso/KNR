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

/* 用空格替换tab, 但是题目提到要间隔不变?
 eg:
 **\tabcd => \tabcd
 a**\tbcdefg => a***bcdefg
 abc*efgh
*/
int main()
{
    int c, nb, nt, pos;

    nb = 0;
    nt = 0;
    // 用来测试1-23
    printf("/**/\n");
    for (pos = 1; (c = getchar()) != EOF; ++pos)
    {
        if (c == ' ')
        {
            if (pos % TABSTOP != 0)
            {
                ++nb;
            }
            else
            {
                nb = 0;
                ++nt;
            }
        }
        else
        {
            for (; nt > 0; --nt)
            {
                myputchar('\t');
            }
            if (c == '\t')
            {
                nb = 0;
            }
            else
            {
                for (; nb > 0; --nb)
                {
                    myputchar(' ');
                }
            }
            myputchar(c);
            if (c == '\n')
            {
                pos = 0;
            }
            else
            {
                pos = pos + (TABSTOP - (pos - 1) % TABSTOP) - 1;
            }
        }
    }
}