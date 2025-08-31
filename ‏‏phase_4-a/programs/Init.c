#include "global.h"
#define IF 261
#define THEN 262
#define WHILE 263
#define DO 264
#define BEGIN 265
#define END 266
struct entry keywords[] = {
    {"div", DIV},
    {"mod", MOD},
     {"if", IF},
         {"then", THEN},
    {"while", WHILE},
    {"do", DO},
    {"begin", BEGIN},
    {"end", END},

           
    {0, 0} // Null terminator
};

void init() {
    struct entry* p;
    for (p = keywords; p->token; p++)
        insert(p->lexptr, p->token);
}