#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointered to a stack
 * @n: line number that opcode is call at.
 */
void pstr(stack_t **stack, unsigned int n)
{
	stack_t *node;
	(void) n;

	if (!stack || !(*stack))
	{
		fprintf(stdout, "\n");
		return;
	}

	node = *stack;
	while (node)
	{
		if (node->n <= 0 || node->n > 127)
			break;
		fprintf(stdout, "%c", node->n);
		node = node->next;
	}
	fprintf(stdout, "\n");
}
