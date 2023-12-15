#include "monty.h"

static instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"rotl", rotl},
		{"rotr", rotr},
		{"swap", swap},
		{"add", add},
		{"pint", pint},
		{"mul", mul},
		{"div", _div},
		{"pstr", pstr},
		{"mod", mod},
		{"sub", sub},
		{"pchar", pchar},
		{"nop", nop},
		{"rotl", rotl},
		{NULL, NULL}
	};
/**
 * call - calls the appropriate function
 * @tokens: pointer to array of tokens
 * @stack: pointer to a stack
 *
 * Return: nothing
 */
void call(char **tokens, stack_t **stack)
{
	int cg = 0;

	while (ops[cg].opcode)
	{
		if (tokens[0][0] == '#')
			return;
		if (strcmp(tokens[0], "queue") == 0)
		{
			data_type = 1;
			return;
		}
		if (strcmp(tokens[0], "stack") == 0)
		{
			data_type = 0;
			return;
		}
		if (strcmp(tokens[0], ops[cg].opcode) == 0)
		{
			if (ops[cg].f)
				ops[cg].f(stack, line_number);
			break;
		}
		cg++;
	}
	if (strcmp(tokens[0], "push") == 0)
	{
		is_usable(tokens, stack);
		(*stack)->n = atoi(tokens[1]);
	}
	else if (!(ops[cg].opcode))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number,
				tokens[0]);
		exit(EXIT_FAILURE);
	}
}
