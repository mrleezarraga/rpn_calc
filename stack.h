#ifndef STACK_H
#define STACK_H
#include "node.h"

float pop(node **st);
int push(node **n,float x);
int read_full_stack(node *st);
int check_depth(node *st, int depth);

#endif