#include "stmt.h"
#include "expr.h"
#include "type.h"
#include "decl.h"

struct stmt * stmt_create( stmt_kind_t kind, struct decl *d, struct expr *init_expr, 
	struct expr *e, struct expr *next_expr, struct stmt *body, struct stmt *else_body )
{
	struct stmt *s = malloc(sizeof(*s));

	s -> kind = kind;
	s -> decl = d;
	s -> init_expr = init_expr;
	s -> expr = e;
	s -> next_expr = next_expr;
	s -> body = body;
	s -> else_body = else_body;

    s -> next = 0;

	return s;
}

void stmt_delete( struct stmt *s )
{
	while ( s ) {
		struct stmt* cur = s;
		s = s -> next;
		decl_delete( cur-> decl );
		expr_delete( cur-> init_expr );
		expr_delete( cur-> expr );
		expr_delete( cur-> next_expr );
		stmt_delete( cur-> body );
		stmt_delete( cur-> else_body );
		stmt_delete( cur-> next );
		free( cur );
	}
}

void stmt_print_indent( indent )
{
	while(indent > 0) {
		printf("\t");
		indent--;
	}
}

void stmt_typecheck( struct stmt *s )
{
    if (!s) return;
    struct type *T;
    switch( s-> kind ) {
         case STMT_DECL:
            decl_typecheck(s->decl);
            break;
        case STMT_EXPR:
            expr_typecheck(s->init_expr);
            break;
        case STMT_IF_ELSE:
        
            T = expr_typecheck(s->init_expr);
            if (T->kind != TYPE_BOOLEAN) {
                decl_has_error = 1;
                printf("type error: if condition cannot be a ");
                type_print(T);
                printf(", it must be a boolean\n");
            }

            stmt_typecheck(s->body);
            stmt_typecheck(s->else_body);
            break;
        case STMT_FOR:
            expr_typecheck(s->init_expr);
            T = expr_typecheck(s->expr);
            if (T -> kind != TYPE_BOOLEAN) {
                decl_has_error = 1;
                printf("type error: for statement must have boolean expression\n");
            }
            expr_typecheck(s->next_expr);
            stmt_typecheck(s->body);
            break;
        case STMT_PRINT:
            T = expr_typecheck(s->init_expr);
            break;
        case STMT_RETURN:
            T = expr_typecheck(s->init_expr);
            // go up one scope and find the first function symbol
            
            if (decl_func_sym) {
                if (!type_compare(T , decl_func_sym->type->subtype)) {
                    decl_has_error = 1;
                    printf("type error: cannot return a ");
                    type_print(T);
                    printf(" in a function(%s) that returns ", decl_func_sym->name);
                    type_print(decl_func_sym->type->subtype);
                    printf("\n");
                }     
            } else {
                // this should never happend
                decl_has_error = 1;
                printf("type error: function symbol not set\n");
            }
            break;
        case STMT_BLOCK:
            stmt_typecheck(s->body);
            break;       
    }
    if (s->next) 
        stmt_typecheck(s->next);
}

void stmt_resolve( struct stmt *s )
{
    if (!s) return;
    switch(s->kind) {
        case STMT_DECL:
            decl_resolve(s->decl, SYMBOL_LOCAL);
            break;
        case STMT_EXPR:
            expr_resolve(s->init_expr);
            break;
        case STMT_IF_ELSE:
            expr_resolve(s->init_expr);
            stmt_resolve(s->body);
            stmt_resolve(s->else_body);
            break;
        case STMT_FOR:
            expr_resolve(s->init_expr);
            expr_resolve(s->expr);
            expr_resolve(s->next_expr);
            stmt_resolve(s->body);
            break;
        case STMT_PRINT:
            expr_resolve(s->init_expr);
            break;
        case STMT_RETURN:
            expr_resolve(s->init_expr);
            break;
        case STMT_BLOCK:
            scope_enter();
            stmt_resolve(s->body);
            scope_exit();
            break;
    }
    if (s->next)
        stmt_resolve( s->next );
}

void stmt_print( struct stmt *s, int indent )
{
	while ( s ) {
    	switch ( s->kind ) {
    		case STMT_DECL:
    			decl_print(s -> decl, indent);
    			break;
    		case STMT_EXPR:
    			stmt_print_indent( indent );
    			expr_print(s -> init_expr);
    			printf(";");
    			break;
    		case STMT_IF_ELSE:
    			stmt_print_indent( indent );
    			printf("if (");
    			expr_print(s -> init_expr);
    			printf(")\n");
    
    			//stmt_print_indent( indent );
    			//printf("{\n");
                if (s->body->kind == STMT_BLOCK)
    			     stmt_print(s->body, indent);
                else
                    stmt_print(s->body, indent+1);
    			//printf("\n");
    			//stmt_print_indent( indent );
    			//printf("}");
    
    			if (s -> else_body) {
    				// if the if statement has else block
                    printf("\n");
                    stmt_print_indent( indent );
    				printf("else \n");
                    if (s->body->kind == STMT_BLOCK)
                        stmt_print(s->else_body, indent);
                    else
                        stmt_print(s->else_body, indent+1);
                    //printf("\n");
    				//stmt_print_indent( indent );
    				//printf("}");
    			}
    			break;
    		case STMT_FOR:
    			stmt_print_indent( indent );
    			printf("for (");
    			expr_print( s->init_expr );
    			printf(";");
    			expr_print( s->expr );
    			printf(";");
    			expr_print( s->next_expr );
    			printf(")\n");
                
                if (s->body->kind == STMT_BLOCK)
                     stmt_print(s->body, indent);
                else
                    stmt_print(s->body, indent+1);
    			break;
    		case STMT_PRINT:
    			stmt_print_indent( indent );
    			printf("print ");
    			struct expr* expr_list = s->init_expr;
    			while ( expr_list ) {
    				expr_print( expr_list);
    				expr_list = expr_list -> next;
    				if (expr_list) printf(",");
    			}			
    			printf(";");
    			break;
    		case STMT_RETURN:
    			stmt_print_indent( indent );
                printf("return ");
    			expr_print( s->init_expr );
    			printf(";");
    			break;
    		case STMT_BLOCK:
                stmt_print_indent( indent );
                printf("{\n");
                stmt_print(s->body, indent+1);
                printf("\n");
                stmt_print_indent( indent );
                printf("}");
    			break;
    	}
        if ((s->next && s->kind != STMT_DECL)) printf("\n");
    	s = s->next;   	
	}
}