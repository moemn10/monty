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
<<<<<<< HEAD
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
size_t p_stack(const stack_t *u);
stack_t *ext_Node(stack_t **kr, const int i);
stack_t *ext_stack_end(stack_t **kr, const int i);
void data_stack(stack_t *kr);
void del_top(stack_t **stack);
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
void Z_div_one(int line_numb);
void Z_mul(int line_num);
void Z_mod(int line_num);
void Z_pchar(int line_num);
void char_emp(int line_num);
int db_ecf(char *fn);
void db_ecl(char *l, int line_num);
int is_emp(char *l);
int Z_num(char *num);
=======
void open_ferror(char *fn);
void pull(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _push(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);
void _pchar(stack_t **stack, unsigned int line_num);
void _pstr(stack_t **stack, unsigned int line_num);
void _queue(stack_t **stack, unsigned int line_num);
void _stack(stack_t **stack, unsigned int line_num);
void _rotl(stack_t **stack, unsigned int line_num);
void _rotr(stack_t **stack, unsigned int line_num);
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
>>>>>>> e7b6c4dcecd72066c7aca9ebd7c16ac5b928d508

#endif
