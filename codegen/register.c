#include "register.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

const char *register_name( int r )
{
	switch(r) {
		case 0:
			return "%rax";
		case 1:
			return "%rbx";
		case 2:
			return "%rcx";
		case 3:
			return "%rdx";
		case 4:
			return "%rsi";
		case 5:
			return "%rdi";
		case 6:
			return "%rbp";
		case 7:
			return "%rsp";
		case 8:
			return "%r8";
		case 9:
			return "%r9";
		case 10:
			return "%r10";
		case 11:
			return "%r11";
		case 12:
			return "%r12";
		case 13:
			return "%r13";
		case 14:
			return "%r14";
		case 15:
			return "%r15";
	}
	return "default";
}

int register_alloc(register_kind_t reg_kind)
{
	int i = 0;
	switch( reg_kind ) {
		case REGISTER_RETURN_VAL:
			i = 10;
			break;
		case REGISTER_GENERAL:
			i = 9;
			break;
		case REGISTER_ONLY_NUM:
			i = 8;
			break;
	}
	for (; i < 16; i++) {
		if (!reg_taken[i]) {
			reg_taken[i] = 1;
			return i;
		}
	}
	printf("error: no free register available for use!");
	exit(1);
}

void register_free( int r )
{
	if (r >= 8)
	reg_taken[r] = 0;
}
