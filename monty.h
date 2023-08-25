#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>

#define STACK 1
#define QUEUE 0
#define STACK_SIZE 100
#define UNUSED(x) (void)(x)
#define INSTRUCTIONS_COUNT 17
#define _GNU_SOURCE


/**
 * struct stacks_ - Doubly linked list representation of a stack or queue
 * @i: int
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack or queue
 *
 * Description: doubly linked list node structure
 */
typedef struct stacks_
{
    int i;
    struct stacks_ *prev;
    struct stacks_ *next;
} stack_t;

/**
 * struct insts_ - op code and its functions
 * @opc: the op code
 * @f: function to handle the op code
 *
 * Description: opcode and its function
 */
typedef struct insts_
{
    char *opc;
    void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;
typedef struct data_s
{
    int line_num;
    char *l;
    char *arg1;
    char *arg2;
    stack_t *stack;
    FILE *file;
    int data_mode;
} data_t;
extern data_t data;
size_t p_stack(const stack_t *u);
stack_t *ext_Node(stack_t **kr, const int i);
stack_t *ext_stack_end(stack_t **kr, const int i);
void data_stack(stack_t *kr);
void delete_top();
void f_All();
void root(void);
void p_val(int line_num, char *op_code_user);
void Z_malloc();
void Z_push(int line_num);
void user_stack(int line_num);
void Z_pint(int line_num);
void Z_swap(int line_num);
void Z_add(int line_num);
void Z_sub(int line_num);
void Z_div(int line_num);
void Z_div_one(int line_num);
void Z_mul(int line_num);
void Z_mod(int line_num);
void Z_pchar(int line_num);
void char_emp(int line_num);
int db_ecf(char *fn);
void db_ecl(char *l, int line_num);
int is_emp(char *l);
int Z_num(char *num);
void open_ferror(char *fn);
void pall(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void queue(stack_t **stack, unsigned int line_num);
void stack(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);
int64_t getline(char **l, size_t *len, FILE *file);
#endif
