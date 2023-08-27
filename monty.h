#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define _GNU_SOURCE

/**
 * struct stack_s - doubly linked list representation of a stack or queue
 * @i: integer number
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack or queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int i;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*Stack operations*/
void p_top(stack_t **, unsigned int);
void pop_up_top(stack_t **, unsigned int);
void pop_up_nop(stack_t **, unsigned int);
void swap_n(stack_t **, unsigned int);
stack_t *create_n(int i);
void free_n(void);
void p_stack(stack_t **, unsigned int);
void add_stack_(stack_t **, unsigned int);
void add_queue_(stack_t **, unsigned int);
void call_fn(op_func, char *, char *, int, int);

/*file operations*/
int p_line(char *buffer, int line_num, int format);
void read_f(FILE *);
int l_char(FILE *);
void open_f(char *file_n);
void find_fn(char *, char *, int, int);

/*Error hanlding*/
void str_errors(int error_s, ...);
void rotr(stack_t **, unsigned int);
void errors_1(int error_s, ...);
void errors_2(int error_s, ...);

/*Strings  operations*/
void p_char(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Math operations nodes*/
void add_n(stack_t **, unsigned int);
void sub_n(stack_t **, unsigned int);
void mul_n(stack_t **, unsigned int);
void mod_n(stack_t **, unsigned int);
void div_n(stack_t **, unsigned int);

#endif
