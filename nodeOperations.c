#include "monty.h"

/**
 * addNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer to a pointing to top node
 * @lineNumber: Interger representing the line number of error.
 */
void addNodes(stack_t **stack, unsigned int lineNumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, lineNumber, "add");

	*stack = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * subNodes - subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer to a pointing to top node
 * @lineNumber: Interger representing the line number of error.
 */
void subNodes(stack_t **stack, unsigned int lineNumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error2(8, lineNumber, "sub");


	*stack = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divNodes - divides the top two elements of the stack.
 * @stack: Pointer to a pointer to a pointing to top node
 * @lineNumber: Interger representing the line number of error.
 */
void divNodes(stack_t **stack, unsigned int lineNumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, lineNumber, "div");

	if ((*stack)->n == 0)
		error2(9, lineNumber);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mulNodes - multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer to a pointing to top node
 * @lineNumber: Interger representing the line number of error.
 */
void mulNodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, line_number, "mul");

	*stack = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modNodes - modulus the top two elements of the stack.
 * @stack: Pointer to a pointer to a pointing to top node
 * @lineNumber: Interger representing the line number of error.
 */
void modNodes(stack_t **stack, unsigned int lineNumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, lineNumber, "mod");

	if ((*stack)->n == 0)
		error2(9, lineNumber);
	*stack = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
