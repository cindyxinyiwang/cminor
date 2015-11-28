#ifndef SCOPE_H
#define SCOPE_H

#include "hash_table.h"
#include "symbol.h"

struct scope_node {
	struct hash_table *table;
	struct scope_node *next;
	struct scope_node *prev;
};


struct scope_node *scope_head;
struct scope_node *scope_tail;

int scope_param_count;
int scope_local_count;

void scope_enter();
void scope_exit();
void scope_bind( const char *name, struct symbol *s );
struct symbol * scope_lookup( const char *name );
struct symbol * scope_lookup_local( const char *name );

#endif