#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the stack_t
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int store = 0;

	if ((stack == NULL) || (*stack == NULL) || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		if (*stack)
			frees_stack(stack);
		exit(EXIT_FAILURE);
	}

	(void) line_number;

	store = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = store;
}
