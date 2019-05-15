#include "monty.h"

/**
 * main - entry point. Decoupled from interpreter modules
 * 		for portability
 * @ac: argument count
 * @av: argument vector
 * Returns: 1 on success, 0 on failure
 */
int main(int ac, char **av)
{
	return interpret(ac, av);
}
