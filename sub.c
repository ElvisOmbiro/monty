#include "monty.h"

/**
 * sub - subtracts the top element of the stack from a second one
 * @stack: pointer to a stack_t
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		if (*stack)
			frees_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_number);
}
