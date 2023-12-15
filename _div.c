#include "monty.h"

/**
 * _div - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @line_number: line number
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		if (*stack)
			frees_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		frees_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_number);
}
