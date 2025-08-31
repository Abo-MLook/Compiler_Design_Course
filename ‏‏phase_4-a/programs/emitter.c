

#include "global.h"

void emit(int t, int tval) 
{
	switch (t)
	{
	
		break;
	case '+':
		fprintf(output, "pop r1\npop r2\nadd r2 r1\npush r2\n");
		break;
	case '-':
		fprintf(output, "pop r1\npop r2\nsub r2 r1\npush r2\n");
		break;
	case '*':
		fprintf(output, "pop r1\npop r2\nmult r2 r1\npush r2\n");
		break;
	case '/':
		fprintf(output, "pop r1\npop r2\nDIV r2 r1\n push r2\n");
		break;
	case DIV:
		fprintf(output, "pop r1\npop r2\nDIV r2 r1 \npush r2\n");
		break;

	case MOD:
		fprintf(output, "pop r1\npop r2\MOD r2 r1 \npush r2\n");
		break;
	case NUM:
		fprintf(output, "push %d\n", tval);
		break;
	case ID:
		fprintf(output, "push %s \n", symtable[tval].lexptr);
		break;
	default:
		fprintf(output,"token %d, tokenval %d", t, tval);
	}
	//fprintf(output," ");
}
