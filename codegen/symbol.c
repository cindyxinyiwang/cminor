#include "symbol.h"

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ) {
	struct symbol *s = malloc(sizeof(*s));

	s -> kind = kind;
	s -> type = type;
	s -> name = name;

	s -> params = 0;
	s -> num_local = 0;

	return s;
}

void symbol_print( struct symbol *s ) {
	switch(s->kind) {
		case SYMBOL_LOCAL:
			printf("local %d", s->which);
			break;
		case SYMBOL_GLOBAL:
			printf("global %s", s->name);
			break;
		case SYMBOL_PARAM:
			printf("param %d", s->which);
		 	break;
	}
}

char * symbol_code( struct symbol *s, int decl_num_params ) {
	int offset;
	switch(s->kind) {
		case SYMBOL_LOCAL:
			offset = 8*(s->which + 1 + decl_num_params);
			char* buffer = malloc(sizeof(char) * 50);
			sprintf(buffer, "-%d(%%rbp)", offset);
			return buffer;
			break;
		case SYMBOL_GLOBAL:
			return s->name;
			break;
		case SYMBOL_PARAM:
			switch (s->which) {
				case 0:
					//return "%%rdi";
					return "-8(%rbp)";
					break;
				case 1:
					//return "%%rsi";
					return "-16(%rbp)";
					break;
				case 2:
					//return "%%rdx";
					return "-24(%rbp)";
					break;
				case 3:
					//return "%%rx";
					return "-32(%rbp)";
					break;
				case 4:
					//return "%%r8";
					return "-40(%rbp)";
					break;
				case 5:
					//return "%%r9";
					return "-48(%rbp)";
					break;
			}
		 	break;
	}		
}