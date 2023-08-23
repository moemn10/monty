#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define STACK 1
#define QUEUE 0

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
    struct stack_s *prev;
    struct stack_s *next;
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
void open_file_error(char *fn);
void pall(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void the_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
size_t print_stack(const stack_t *h);
stack_t *add_node(stack_t **hd, const int n);
stack_t *add_stackint_end(stack_t **hd, const int n);
void free_stack(stack_t *hd);
void delete_top(stack_t **stack);
void free_all();
void pusage(void);
void pinvalid_instruction(int line_number, char *opcode_instruction);
void pmalloc_error();
void ppush_error(int line_number);
void pempty_stack(int line_number);
void ppint(int line_number);
void pswap(int line_number);
void padd(int line_number);
void psub(int line_number);
void pdiv(int line_number);
void pdiv_zero(int line_number);
void pmul(int line_number);
void pmod(int line_number);
void ppchar(int line_number);
void pchar_stack_empty(int line_number);
int execf(char *fn);
void execl(char *l, int line_number);
int is_emptyl(char *l);
int is_num(char *num);

#endif
