#include "monty.h"

data_t data = INIT_DATA; 

/**
 * interpret - Primary starting point for program
 * @ac: argument count
 * @av: argument vector
 * Returns: 1 on success, 0 on failure
 */
int interpret(int ac, char **av)
{	
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		return (EXIT_FAILURE);
	}

	data.fp = fopen(av[1], "r");
	if (!data.fp)
	{
		if (errno == EACCES)
			dprintf(STDERR_FILENO, "Error: EACCES\n");
		else if (errno == ENOENT)
			dprintf(STDERR_FILENO, "Error: ENOENT\n");
		else
			dprintf(STDERR_FILENO, "Error: FILE PTR NULL\n");
		return (EXIT_FAILURE);
	}

	parse_opcodes();
	
	return (EXIT_SUCCESS);
}

/**
 * parse_opcodes - parses opcodes read from script file
 */
void parse_opcodes()
{
	ssize_t rbytes = 0;
	size_t n = 0;
	int i = 0;

	while (1)
	{
		rbytes = getline(&(data.line), &n, data.fp);
		if (rbytes == -1)
			break;
		data.words = strtow(data.line, " \t\n");
		if (data.words)
		{
			for (i = 0; data.words[i]; i++)
				;
			data.num_words = i;
			exec_opcode(data.words[0]);
		}

		data.line_number++;
		free_data(0);
	}

	free_data(1);
}

/**
 * exec_opcode - Executes the given opcode if valid
 * @word: the opcode string
 * Returns: 1 on success, 0 on failure
 */
int exec_opcode(char *word)
{
	instruction_t opcodes[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"nop", opcode_nop},
		{"add", opcode_add},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{NULL, NULL}
	};

	int i = 0;

	for (; opcodes[i].opcode; i++)
	{
		if (!strcmp(word, opcodes[i].opcode))
		{
			opcodes[i].f(&data.stack, data.line_number);
			return (1);
		}
	}
	dprintf(STDERR_FILENO, "Opcode %s not found! On line: %d\n",
		word, data.line_number);
	return (0);
}
