#include "monty.h"

/**
 * is_emp - check if  the line empty or not
 * @l: the line that will be checked
 * Return: 1 if line is empty.
 */

int is_emp(char *l)
{
	int len = strlen(l);
	int n;

	if (len > 0)
	{
		if (l[len - 1] == '\n')
		{
			for (n = 0; n < len - 1; n++)
			{
				if (l[n] != ' ')
					return (1);
			}
			return (0);
		}
	}
	return (0);
}


/**
 * db_ecf- executing operations in file
 * @fn: name of the file that has the operations
 * Return: 0 if success, if -1 failure
 */
int db_ecf(char *fn)
{
	char *l = NULL;
	FILE *file;
	ssize_t reading;
	size_t len = 0;
	data_t data;

	data.stack = NULL;
	file = fopen(fn, "r");
	if (file == NULL)
		open_ferror(fn);
	data.file = file;
	while ((reading = getline(&l, &len, file)) != -1)
	{
		data.line_num++;
		data.l = l;
		if (is_emp(data.l) == 1)
			db_ecl(data.l, data.line_num);
	}
	data_stack(data.stack);
	fclose(file);
	free(l);
	return (0);
}


/**
 * db_ecl- executing a single operations line
 * @l: operation's line
 * @line_num: current operation's line number
 */
void db_ecl(char *l, int line_num)
{
	int is_in = -1;
	int n;
	data_t data;
	instruction_t insts[] = {
		{"push", _push},
		{"sub", _sub},
		{"div", _div},
		{"add", _add},
		{"mul", _mul},
		{"mod", _mod},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pop", _pop},
		{"pall", pull},
		{"pint", _pint},
		{"swap", _swap},
		{"nop", _nop},
		{"pchar", _pchar},
		{"queue", _queue},
		{"stack", _stack},
	};
	data.arg1 = strtok(l, " \n");
	data.arg2 = strtok(NULL, " \n");
	if (data.arg1[0] == '#')
	{
		_nop(&data.stack, line_num);
		return;
	}
	for (n = 0; n < INSTRUCTIONS_COUNT; n++)
		if (strcmp(data.arg1, insts[n].opc) == 0)
		{

			is_in = n;
			break;
		}
	if (is_in != -1)
		insts[n].f(&data.stack, line_num);
	else
		p_val(line_num, data.arg1);
}
