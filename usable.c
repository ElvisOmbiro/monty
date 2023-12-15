#include "monty.h"

/**
 * is_usable - check if second spot of a token array is valid
 * @token: tokens value to check
 * @stack: pointer to a stack
 */
void is_usable(char **token, stack_t **stack)
{
	int cg = 0;

	if (!token[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		if (*stack)
			frees_stack(stack);
		free(token);
		exit(EXIT_FAILURE);
	}

	while (token[1][cg])
	{
		if (token[1][cg] == '-' && cg == 0)
			cg++;
		if (isdigit(token[1][cg]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			if (*stack)
				frees_stack(stack);
			free(token);
			exit(EXIT_FAILURE);
		}
		cg++;
	}
}
