#include "global.h"


int tok = NONE;

void parse()
{
    lookahead = lexan();
    stmt();
    match(DONE);
}


void stmt() {

    switch (lookahead)
    {
    case ID: 
        tok = tokenval;
        match(ID);
        match('=');
        expr();
        fprintf(output, "pop %s \n", symtable[tok].lexptr);
        break;
    case IF:
        match(IF);
        match('(');
        expr();
        match(')');
        match(THEN);
        fprintf(output, "pop r2\ncmp r2,0\nbe else\n");
        stmt();
        fprintf(output, "else:\n");
        break;

    case WHILE:
        match(WHILE);
        match('(');
        expr();
        match(')');
        match(DO);
        fprintf(output, "pop r2\ncmp r2,0\nbe endwhile\n");
        stmt();
        fprintf(output, "b while\nendwhile:\n");
        break;

    case BEGIN:
        match(BEGIN);
        CS();
        match(END);
        break;


    default:
        error("SYNTEX ERROR\n");
        break;
    }


}


void CS() {

    while (lookahead != DONE  && lookahead!= END) {
        stmt();
        match(';');
        

    }

   
}

void expr()
{
    int t;
    term();

    while (1)
        switch (lookahead)
        {
        case '+':
        case '-':
            t = lookahead;
            match(lookahead);
            term();
            emit(t, NONE);
            continue;
        default:
            return;
        }
}
void term()
{
    int t;
    factor();
    while (1)
        switch (lookahead)
        {
        case '*':
        case '/':
        case DIV:
        case MOD:
            t = lookahead;
            match(lookahead);
            factor();
            emit(t, NONE);
            continue;
        default:
            return;
        }
}
void factor()
{
    switch (lookahead)
    {
    case '(':
        match('(');
        expr();
        match(')');
        break;
    case NUM:
        emit(NUM, tokenval);
        match(NUM);
        break;
    case ID:
        emit(ID, tokenval);
        match(ID);
        break;
    default:
        error("syntax ");
    }
}

void match(t) int t;
{ 
    if (lookahead == t) {
        lookahead = lexan();
    }
    else {
        fprintf(output, "%d   %d", lookahead, t);
        error(" error");
    }
}
