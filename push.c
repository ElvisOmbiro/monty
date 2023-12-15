#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: head of the stack
 * @n: line number
 */
void push(stack_t **stack, unsigned int n)
{
	stack_t *node = NULL, *tmp = NULL;
	(void) n;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		frees_stack(stack);
		exit(EXIT_FAILURE);
	}

	node->prev = node->next = NULL;

	if (!(*stack))
		(*stack) = node;
	else
	{
		/*data_type = 0 for stack, 1 for queue*/
		if (data_type == 0)
		{
			(*stack)->prev = node;
			node->next = *stack;
			*stack = node;
		}
		else
		{
			tmp = *stack;
			while(tmp->next)
				tmp = tmp->next;
			node->prev = tmp;
			tmp->next = node;
		}
	}
}

/**
 * nop - does nothing
 * stack: pointer to the head of the stack
 * @line_number: line_nunmber
 */
void nop(stack_t **stack, unsigned line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * rotl -  rotates the stack to the top
 * stack: pointer to the head of the stack
 * @line_number: line_nunmber
 */

void rotl(stack_t **stack, unsigned line_number)
{
	stack_t *tmp1, *tmp2;

	(void) stack;
	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	tmp1 = *stack;
	tmp2 = tmp1->next;
	*stack = tmp2;
	while (tmp2)
	{
		if (tmp2->next == NULL)
		{
			tmp2->next = tmp1;
			tmp1->next = NULL;
			tmp1->prev = tmp2;
			break;
		}

		tmp2 = tmp2->next;
	}
}

/**
 * rotr -  rotates the stack to the bottom
 * stack: pointer to the head of the stack
 * @line_number: line_nunmber
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *last;

	(void) stack;
	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			last = tmp;
			break;
		}
		tmp = tmp->next;
	}

	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;

	*stack = last;
}
