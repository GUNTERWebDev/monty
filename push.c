#include "monty.h"
diff_t diff;
void push(stack_t **stack, unsigned int count)
{
        int n, j = 0, flag = 0;
        printf("%s\n", diff.arg);
        if (diff.arg == NULL)
        {
                fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(diff.fd);
                free_stack(*stack);
                free(diff.cmd);
		exit(EXIT_FAILURE);
        }
        if (diff.arg[0] == '-')
                j++;
        for (; diff.arg[j] != '\0'; j++)
        {
                if (diff.arg[j] > 57 || diff.arg[j] < 48)
                        flag = 1;
        }
        if (flag == 1)
        {
                fprintf(stderr, "L%d: usage: push integer\n", count);
                fclose(diff.fd);
                free_stack(*stack);
                free(diff.cmd);
		exit(EXIT_FAILURE);
        }

        n = atoi(diff.arg);
        if (diff.lifi == 0)
                addnode(stack, n);
        else
                add_queue(stack, n);
}
