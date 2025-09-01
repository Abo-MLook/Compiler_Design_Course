#ifndef GLOBAL_H
#define GLOBAL_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BSIZE 128
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

#define IF 261
#define THEN 262
#define WHILE 263
#define DO 264
#define BEGIN 265
#define END 266

#define MAIN 268
#define FUNCTION 267




#define STRMAX 999
#define SYMMAX 100

#define STRMAX 999
#define SYMMAX 100
void CS();
void init();
void parse();
void init();
void error(char* m);
int lookup(char s[]);
int insert(char s[], int tok);
int lexan();
void expr();
void term();
void factor();
void emit(int, int);
void stmt();
void match(int t);
void dec();
void funcdec();
void mainfun();
void rest();

extern FILE* output , *input , *err;;

extern int tokenval;
extern int lookahead;
extern int lineno;
extern int tok;

struct entry
{
    char* lexptr;
    int token;
};

extern struct entry symtable[];
#endif