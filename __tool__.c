#include "monty.h"

/**
 * open_f - opening  file operation
 * @file_n: file name path
 * Return: void
 */

void open_f(char *file_n)
{
	FILE *fd = fopen(file_n, "r");

	if (file_n == NULL || fd == NULL)
		errors_1(2, file_name);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - reading a file operation
 * @fd: P to file des
 * Return: void
 */

void read_f(FILE *fd)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t l = 0;

	for (line_num = 1; getline(&buffer, &l, fd) != -1; line_num++)
	{
		format = p_line(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * p_line - change the line into token to cal
 * Which func to call
 * @buffer: Line from the file opertaion
 * @line_num: number's of line
 * @format:  Storage format. If 0 Nodes will be come as a stack.
 * if 1 nodes will be come as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int p_line(char *buffer, int line_num, int format)
{
	char *opcode, *val;
	const char *del = "\n ";

	if (buffer == NULL)
		errors_1(4);

	opcode = strtok(buffer, del);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, del);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_fn(opcode, val, line_num, format);
	return (format);
}

/**
 * find_fn - finding the app function for the opcode
 * @opcode: opcode opearion
 * @val: arg of opcode
 * @format:  Storage format. If 0 node will be exists as a stack.
 * @lnm: number's of line
 * if 1 nodes will be exists as a queue.
 * Return: void
 */
void find_fn(char *opcode, char *val, int lnm, int format)
{
	int n;
	int fl;

	instruction_t func_list[] = {
		{"push", add_stack_},
		{"pall", p_stack},
		{"pint", p_top},
		{"pop", pop_up_top},
		{"nop", pop_up_nop},
		{"swap", swap_n},
		{"add", add_n},
		{"sub", sub_n},
		{"div", div_n},
		{"mul", mul_n},
		{"mod", mod_n},
		{"pchar", p_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fl = 1, n = 0; func_list[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, func_list[n].opcode) == 0)
		{
			call_fn(func_list[n].f, opcode, val, lnm, format);
			fl = 0;
		}
	}
	if (fl == 1)
		errors_1(3, lnm, opcode);
}


/**
 * call_fn - Calling the function we want.
 * @fn: P to the func that will be called.
 * @op: str that gives the opcode.
 * @val: str that gives a numeric value.
 * @lnm: number of lines for the instr.
 * @format: Format specifier. If 0 nde will be exists as a stack.
 * if 1 nod will be exists as a queue.
 */
void call_fn(op_func func, char *op, char *val, int lnm, int format)
{
	stack_t *node;
	int fl;
	int n;

	fl = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fl = -1;
		}
		if (val == NULL)
			errors_1(5, ln);
		for (n = 0; val[n] != '\0'; n++)
		{
			if (isdigit(val[n]) == 0)
				errors_1(5, lnm);
		}
		node = create_n(atoi(val) * fl);
		if (format == 0)
			func(&node, lnm);
		if (format == 1)
			add_queue_(&node, ln);
	}
	else
		func(&head, lm);
}
