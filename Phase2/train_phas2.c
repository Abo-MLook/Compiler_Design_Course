#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void expr();
void term();
void match(int c);
void error();
int lexam(); // lok = getchar()           lok = lexam()

int lookahead;
#define NUM 256
int tocanval;
int lineN = 1;

int main()
{
    lookahead = lexam();
    expr();
    return 0;
}

int lexam()
{
    int temp;

    while (1)
    {
        temp = getchar(); // 1    + 224            1 224 +             234    2 34   234   tocanval = 234              lokahed = num
        if (temp == ' ' || temp == '\t')
        {
            continue;
        }
        if (temp == '\n' || temp == EOF)
        {
            return EOF;
        }

        if (isdigit(temp))
        {
            ungetc(temp, stdin);
            scanf("%d", &tocanval);
            return NUM;
        }

        return temp;
    }
}

void expr(void)
{
    term();
    while (1)
    {

        if (lookahead == '+')
        {
            match(lookahead); //! move to the next digit the come after + and print it  1 + (3)    // printed  1
            term();
            putchar(' '); //!  print the digit                                                      // printed  1 3
            putchar('+'); //! print +  after printing the digit came after it                       // printed  1 3 +
        }
        else if (lookahead == '-')
        {
            match(lookahead);
            term();
            putchar('-');
        }
        else if (lookahead == '\n')
        {
            lineN++;
        }

        else if (lookahead == EOF)
        {
            return; // End expression
        }

        else
        {
            error();
        }
        /* code */
    }
};

void term()
{
    putchar(' ');
    if (lookahead == NUM)
    {
        printf("%d", tocanval);
        match(lookahead);
    }
    else
        error();
}

void match(int c)
{

    if (lookahead == c)
    {
        lookahead = lexam();
    }
    else
        error();
}

void error()
{

    printf("error has accrued you did not enter valid number");
    exit(1);
}
