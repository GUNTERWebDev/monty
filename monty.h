#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct diff_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct diff_s
{
	char *arg;
	FILE *fd;
	char *cmd;
	int lifi;
}  diff_t;
extern diff_t diff;
void read_monty(FILE *fd);
void free_stack(stack_t *head);
void execute(char *cmd, unsigned int count, stack_t **stack, FILE *fd, diff_t diff);
stack_t  *add_dnodeint(stack_t  **head, const int n);
void pint(stack_t **head, unsigned int count);
void addqueue(stack_t **head, int n);
int _atoi(char *nptr, char **endptr, int base);
void push(stack_t **stack, unsigned int count, diff_t diff);
void pall(stack_t **head, unsigned int counter, diff_t diff);

#endif
