#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

#include <unistd.h>

#include <string.h>

#include <stdlib.h>

#include <ctype.h>

#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack or queue
 * @n: integer stored in node
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack or queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s {
  int n;
  struct stack_s * prev;
  struct stack_s * next;
}
stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s {
  char * opcode;
  void( * f)(stack_t ** stack, unsigned int line_number);
}
instruction_t;

extern stack_t * head;
typedef void( * op_func)(stack_t ** , unsigned int);


void openFile(char * file_name);
int seprateLine(char * buffer, int line_number, int format);
void readFile(FILE * );
int lengthChars(FILE * );
void findfunction(char * , char * , int, int);


stack_t *addNode(int n);
void freeNodes(void);
void printStack(stack_t ** , unsigned int);
void addToStack(stack_t ** , unsigned int);
void addToQueue(stack_t ** , unsigned int);

void callFunction(op_func, char * , char * , int, int);

void printTop(stack_t ** , unsigned int);
void popTop(stack_t ** , unsigned int);
void nop(stack_t ** , unsigned int);
void swapNodes(stack_t ** , unsigned int);


void addNodes(stack_t ** , unsigned int);
void subNodes(stack_t ** , unsigned int);
void divNodes(stack_t ** , unsigned int);
void mulNodes(stack_t ** , unsigned int);
void modNodes(stack_t ** , unsigned int);


void printChar(stack_t ** , unsigned int);
void printStr(stack_t ** , unsigned int);
void rotateFirstBottom((stack_t ** , unsigned int);


void error(int error_code, ...);
void error2(int error_code, ...);
void stringError(int error_code, ...);
void rotateLastTop(stack_t ** , unsigned int);

#endif
