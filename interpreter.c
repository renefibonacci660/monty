#include "monty.h"

data_t data = INIT_DATA; 

void main_loop();
int get_opcode(char *word);

int main(int ac, char **av)
{
	FILE *file_ptr = NULL;
	
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		return (EXIT_FAILURE);
	}

	file_ptr = fopen(av[1], "r");
	if (!file_ptr)
	{
		if (errno == EACCES)
		{
			dprintf(STDERR_FILENO, "EACCES\n");
			exit(126);
		}
		if (errno == ENOENT)
		{
			dprintf(STDERR_FILENO, "ENOENT\n");
			exit(127);
		}
		dprintf(STDERR_FILENO, "FILE_PTR NULL!\n");
		return (EXIT_FAILURE);
	}
	data.file_ptr = file_ptr;

	main_loop();

	fclose(file_ptr);

	return (EXIT_SUCCESS);
}

void main_loop()
{
	char *lineptr = NULL, **words = NULL;
	ssize_t rbytes = 0;
	size_t n = 0;
	int i = 0;

	while (1)
	{
		rbytes = getline(&lineptr, &n, data.file_ptr);
		if (rbytes == -1)
			break;
		words = strtow(lineptr, " \t\n"); /* TODO: what if they added a newline? */	
		data.words = words;
		for (i = 0; words[i]; i++)
			;
		data.num_words = i;

		get_opcode(words[0]);

		data.line_number++;
		if (lineptr)
		{
			free(lineptr);
			lineptr = NULL;
			ffree(data.words);
			data.words = NULL;
		}
	}

	if (lineptr)
		free(lineptr);
	if (data.stack)
		free_dlistint(data.stack);
}

int get_opcode(char *word)
{
	instruction_t opcodes[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"nop", opcode_nop},
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
