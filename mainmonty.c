#include "monty.h"

unsigned int line_number = 0;
unsigned int data_type = 0; /*0 for stack 1 for queue*/

/**
 * main - the main function controling the program flow
 * @argc: argument count
 * @argv: argument list
 * Return: Nothing
 */
int main(int argc, char *argv[])
{
	char **tokens = NULL;
	stack_t *head = NULL;
	char *buffer = NULL;
	FILE *k;
	size_t n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	k = fopen(argv[1], "r+");
	if (k == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&buffer, &n, k)) != -1)
	{
		line_number++;
		tokens = tokenize(buffer);
		if (tokens)
		{
			call(tokens, &head);
			free(tokens);
		}
	}
	free(buffer);
	frees_stack(&head);
	fclose(k);

	return (0);
}
