#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int lookAhead;

void expr(void);   // term rest           1 + 3 - 4
void term(void);   // 1
void rest(void);   //
void match(int t); // 1 + 3 - 4
void error(void);

int main()
{
    lookAhead = getchar();
    expr();
    return 0;
};

void expr(void)
{
    term();
    rest();
};

void term(void)
{
    if (isdigit(lookAhead))
    {

        putchar(lookAhead);
        match(lookAhead);
    }

    else
    {
        error();
    }
};

void rest(void)
{
    if (lookAhead == '+')
    {
        match(lookAhead);
        term();
        putchar('+');
        rest();
    }
    else if (lookAhead == '-')
    {
        match(lookAhead);
        term();
        putchar('-');
        rest();
    }
    else if (lookAhead == '\n' || lookAhead == EOF)
    { //  Valid end of input
        return;
    }
    else
    {
        error(); //  Stop if an invalid character is found!
    }
}

void match(int t)
{

    if (lookAhead == t)
    {
        lookAhead = getchar();
    }
    else
    {
        error();
    }
};

void error(void)
{
    printf(" Error has accured");
    exit(1);
}

//