#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to a stack_t
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		if (*stack)
			frees_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_number);
}
