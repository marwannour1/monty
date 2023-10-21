#include "monty.h"

/**
 * createNode - Adds a node to the stack.
 * @n: number to assign to node.
 * 
 * Returns: Pointer to the newly created node
 */
stack_t *createNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeNodes - Frees all nodes in the stack.
 */
void freeNodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * addToQueue - Adds a new node to the queue.
 * @newnode: Pointer to the new created node.
 * @lineNumber: line number for error.
 */
void addToQueue(stack_t **newNode, unsigned int lineNumber)
{
	stack_t *tmp;
    (void)lineNumber;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newNode;
	(*newNode)->prev = tmp;

}

/**
 * addToStack - Adds a new node to the stack.
 * @newnode: Pointer to the new created node.
 * @lineNumber: line number for error.
 */
void addToStack(stack_t **newNode, unsigned int lineNumber)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	head = *newNode;
	head->next = tmp;
	tmp->prev = head;
}
