#include "scope.h"
#include "hash_table.h"
#include "symbol.h"


// delete a scope_node 
// does not delete the node it links to
void scope_node_delete(struct scope_node *node) {
	hash_table_clear(node->table);
	hash_table_delete(node->table);
	free( node );
}

void scope_enter()
{
	struct scope_node *new_scope_node = malloc(sizeof(*new_scope_node));
	new_scope_node->table = hash_table_create(0,0);
	if (!scope_head) {
		scope_head = new_scope_node;
		scope_tail = new_scope_node;
	} else {
		scope_tail -> next = new_scope_node;
		new_scope_node -> prev = scope_tail;
		scope_tail = scope_tail -> next;
	}
}

void scope_exit()
{
	if (!scope_head) return;

	if (scope_head == scope_tail) {
		scope_node_delete( scope_head );
		scope_node_delete( scope_tail );
	} else {
		struct scope_node *new_tail = scope_tail->prev;
		scope_node_delete( scope_tail );
		scope_tail = new_tail;
	}

	// reset counts
	if (scope_head == scope_tail) {
		scope_local_count = 0;
		scope_param_count = 0;
	}
}

void scope_bind( const char *name, struct symbol *s )
{
	if (!scope_head) {
		scope_enter();
	}
	hash_table_insert(scope_tail -> table, name, s);
	// set the symbol count
	if (s->kind == SYMBOL_LOCAL) {
		s->which = scope_local_count;
		scope_local_count++;
	} else if (s->kind == SYMBOL_PARAM) {
		s->which = scope_param_count;
		scope_param_count++;
	}
}

struct symbol * scope_lookup( const char *name )
{

	struct scope_node *current_scope = scope_tail;
	struct symbol *result;
	while (current_scope) {
		result = (struct symbol *)hash_table_lookup(current_scope->table, name);
		if (result) {
			return result;
		}
		current_scope = current_scope -> prev;
	}
	return NULL;
}

struct symbol * scope_lookup_local( const char *name )
{
	struct symbol *result;
	if (!scope_tail) return NULL;
	result = (struct symbol *)hash_table_lookup(scope_tail->table, name);
	if (result) {
		return result;
	}
	return NULL;
}