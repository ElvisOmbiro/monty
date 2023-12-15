#include "monty.h"

/**
 * frees_stack - free the stack
 * @stack: ptr to stack
 * Return: Nothing
 */
void frees_stack(stack_t **stack)
{
        stack_t *head = *stack;

        while (head)
        {
                if (!head->next)
                {
                        free(head);
                        break;
                }
                head = head->next;
                free(head->prev);
        }
}
