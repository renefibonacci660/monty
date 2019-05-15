#include "monty.h"

/**
 * data - data struct singleton pattern, returns pointer to our secret struct
 */
data_t *data(void)
{
	static data_t _data = INIT_DATA;
	return &(_data);
}

/**
 * free_data - central controller method which frees all allocated data
 * @all - on if freeing all data, such as on exit, else just some
 */
void free_data(int all)
{
	/* this is freed every loop iteration since getline() allocates each time */
	if (data()->line)
	{
		free(data()->line);
		data()->line = NULL;
		/* words are malloced separately from data()->line by strtow() */
		ffree(data()->words);
		data()->words = NULL;
	}
	/* this is freed at normal or forced exit */
	if (all)
	{
		if (data()->stack)
		{
			free_dlistint(data()->stack);
			data()->stack = NULL;
		}
		/* not a free, but a clean_up, and this is the perfect place for it */
		if (data()->fp)
		{
			fclose(data()->fp);
			data()->fp = NULL;
		}
	}
}
