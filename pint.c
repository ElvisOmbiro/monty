#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointered to a stack
 * @n: line number that opcode is call at.
 */
void pint(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
