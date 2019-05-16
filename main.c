#include "monty.h"

/**
 * main - entry point. Decoupled from interpreter modules
 *    for portability
 * @ac: argument count
 * @av: argument vector
 * Return: 1 on failure, 0 on success
 */
int main(int ac, char **av)
{
	return (interpret(ac, av));
}
