#include "global.h"

char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;
int lookahead;

int lexan()
{

    int t;

    while (1)
    {
        t = fgetc(input);
        if (t == ' ' || t == '\t')
            ;
        else if (t == '\n')
            lineno = lineno + 1;
        else if (isdigit(t))
        {
            ungetc(t, input);
            fscanf_s(input,"%d", &tokenval);
            return NUM;
        }
        else if (isalpha(t))
        {
            int p, b = 0;
            while (isalnum(t))
            {
                lexbuf[b] = t;
                t = fgetc(input);
                b = b + 1;
                if (b >= BSIZE)
                    error("compiler error");
            }

            lexbuf[b] = EOS;
            if (t != EOF)
                ungetc(t, input);
            p = lookup(lexbuf);
            if (p == 0)
                p = insert(lexbuf, ID);
            tokenval = p;
            return symtable[p].token;
        }
        else if (t == EOF)
            return DONE;
        else
        {
            tokenval = NONE;
            return t;
        }
    }
}

