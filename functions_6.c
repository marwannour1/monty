#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t ** stack, unsigned int line_number) {
  (void) stack;
  (void) line_number;
}

/**
 * swapNodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swapNodes(stack_t ** stack, unsigned int line_number) {
  stack_t * tmp;

  if (stack == NULL || * stack == NULL || ( * stack) -> next == NULL)
    error2(8, line_number, "swap");
  tmp = ( * stack) -> next;
  ( * stack) -> next = tmp -> next;
  if (tmp -> next != NULL)
    tmp -> next -> prev = * stack;
  tmp -> next = * stack;
  ( * stack) -> prev = tmp;
  tmp -> prev = NULL;
  * stack = tmp;
}

/**
 * popTop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void popTop(stack_t ** stack, unsigned int line_number) {
  stack_t * tmp;

  if (stack == NULL || * stack == NULL)
    error2(7, line_number);

  tmp = * stack;
  * stack = tmp -> next;
  if ( * stack != NULL)
    ( * stack) -> prev = NULL;
  free(tmp);
}

/**
 * printTop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void printTop(stack_t ** stack, unsigned int line_number) {
  if (stack == NULL || * stack == NULL)
    error2(6, line_number);
  printf("%d\n", ( * stack) -> n);
}
