#include <stdio.h>

void echo_block_comment();
void echo_line_comment();
void echo_quote(int);
void remove_comments(int);

int main()
{
    int c, d;

    int in_block_comment = 0;
    int in_line_comment = 0;


    while ((c = getchar()) != EOF)
    {
        remove_comments(c);
    }
}