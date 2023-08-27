#include "monty.h"

/**
 * delete_top - deleting node
 * @stack: number of stack
 * return : void
*/
void delete_top()
{
	int top = -1;
	if (top < 0)
	{
		fprintf(stderr, "L%d: stack underflow\n", top);
		f_All();
		exit(EXIT_FAILURE);
	}
	top--;
}
