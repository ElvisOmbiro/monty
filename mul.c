#include "monty.h"

/**
 * mul - multiplies second top element of stack with  top element
 * @stack: pointer to stack_t
 * @line_number: number of lines
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		if (*stack)
			frees_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);
}
