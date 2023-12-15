#include "monty.h"

/**
 * rotr - rotate a linked list to the right
 * @stack: ptr to top of stack
 * @n: line number
 */
void rotr(stack_t **stack, unsigned int n)
{
	stack_t *h = NULL, *t = NULL;

	(void) n;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	t = h = *stack;
	 /* save address of second node */
	while (h->next)
		h = h->next;

	h->prev->next = NULL;
	h->next = t;
	h->prev = NULL;
	t->prev = h;
	*stack = h;
}
