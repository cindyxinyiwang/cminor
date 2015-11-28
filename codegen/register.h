#ifndef REGISTER_H
#define REGISTER_H

// maps index to reg names
const char *reg_names[16];

// indicate if a register is available
int reg_taken[16];

const char *register_name( int r );
int register_alloc();
void register_free( int r );


#endif