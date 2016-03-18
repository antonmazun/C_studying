#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    //queue_t *line;
    visitor_t *visitor = (visitor_t *) malloc(sizeof(visitor_t));
    queue_t * line = queue_new();
    char ch;

    queue_new(line);
    puts("put [a] to add a value.");
    puts("put [d] to delete a value");
    puts("put [q] to quit the program.");

    while((ch = getchar()) != 'q')
    {
        if(ch != 'a' && ch != 'd') //ignore another stuff here
            continue;
        if(ch == 'a')
        {
            printf("What value you want to add: ");
            scanf("%d", visitor);
            if(!queue_isFull(line))
            {
                printf("Adding %d into queue...\n", *visitor);
                queue_enqueue(*visitor, line);
            }
            else
                puts("Queue is full.");
        }
        else
        {
            if(queue_isEmpty(line))
                puts("No items to delete.");
            else
            {
                queue_dequeue(visitor, line);
                printf("Deleting %d from the queue...\n", *visitor);
            }
        }
        printf("%d elements in the queue.\n", queue_itemCount(line));
        puts("print [a] to add a value, [d] to delete a value, [q] to quit the program: ");
    }
    queue_delete(line);
    puts("End of the program");
    return (0);
}
