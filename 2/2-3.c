#include <stdio.h>

int htoi(char s[])
{
    int i = 0;
    if (s[i] == '0')
    {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
        {
            ++i;
        }
    }
    int hexdigit;
    int n = 0;
    int inhex = 1;
    for (; inhex == 1; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            hexdigit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            hexdigit = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            hexdigit = s[i] - 'A' + 10;
        }
        else
        {
            inhex = 0;
        }
        if (inhex == 1)
        {
            n = 16 * n + hexdigit;
        }
    }
    return n;
}

//
int getline(char s[], int maxline)
{
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < maxline - 2)
        {
            s[i] = c;
            ++j;
        }
    }
    if (c == '\n')
    {
        s[j++] = c;
        ++i;
    }
    s[j] = '\0';
    return i;
}

int main()
{
    char s[1000];
    getline(s, 1000);
    printf("htoi, %s => %d\n", s, htoi(s));
}