#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointered to the stack
 * @n: line number that opcode is call at.
 */
void pchar(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
		frees_stack(stack);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}
