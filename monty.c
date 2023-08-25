#include "monty.h"

/**
 * main - function for the Monty interpreter program
 * @argv: arg array of strings
 * @argc: arg int
 * Return: 0 if success, -1 if failed
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		root();
	return (db_ecf(argv[1]));

}
