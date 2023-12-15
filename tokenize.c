#include "monty.h"

/**
 * tokenize - tokenizes a given buffer
 * @buffer:the string that is to be tokenized
 *
 * Return: an array
 */
char **tokenize(char *buffer)
{
	char *token = NULL;
	char **store;
	int cg = 3;
	char *delim = "\t  \r\n";

	token = strtok(buffer, delim);

	if (token == NULL)
		return (NULL);

	store = malloc(sizeof(char **) * 3);
	if (store == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	while (--cg)
		store[cg - 1] = NULL;

	while (token)
	{
		if (cg < 3)
			store[cg] = token;
		token = strtok(NULL, delim);
		cg++;
	}

	store[2] = NULL;

	return (store);
}
