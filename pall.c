#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: pointer to a stack_t
 * @n: line number
 */
void pall(stack_t **stack, unsigned int n)
{
	stack_t *node, *head;
	(void) n;

	if (!stack || !(*stack))
		return;
	node = head = *stack;

	while (node)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}
