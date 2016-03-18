#include <stdio.h> // fprintf
#include <stdlib.h> // malloc free exit

#include "queue.h" // basic prototypes, 'typedef's and 'define's

// private encapsulated structures:
/*
struct visitor_s {
    long arrive;
    int processtime;
};
*/
struct queue_s {
    node_t * front;
    node_t * rear;
    int items;
};

struct node_s {
    visitor_t visitor;
    struct node_s * next;
};

// public methods:
queue_t *queue_new()
{
    queue_t * out = (queue_t *) malloc(sizeof(queue_t));
    out->front = out->rear = NULL;
    out->items = 0;
    return (out);
}
void queue_delete(queue_t * self)
{
    visitor_t tmp;
    while(!queue_isEmpty(self))
        queue_dequeue(&tmp, self);
}
bool queue_isEmpty(const queue_t * self)
{
    return (self->items == 0);
}
bool queue_isFull(const queue_t * self)
{
    return (self->items == MAXQUEUE);
}
int queue_itemCount(const queue_t * self)
{
    return (self->items);
}
bool queue_enqueue(visitor_t visitor, queue_t * self)
{
    node_t * pnew;
    if(queue_isFull(self))
        return (false);
    pnew = (node_t *) malloc(sizeof(node_t));
    if(NULL == pnew)
    {
        fprintf(stderr, "Cannot reserve memory for pointer.\n");
        exit(1);
    }
    pnew->visitor = visitor;
    pnew->next = NULL;
    if(queue_isEmpty(self))
        self->front = pnew;
    else
        self->rear->next = pnew;
    self->rear = pnew;
    self->items++;
    return (true);
}
bool queue_dequeue(visitor_t * visitor_deleted, queue_t * self)
{
    node_t * pt;
    if(queue_isEmpty(self))
        return (false);
    *visitor_deleted = self->front->visitor;
    pt = self->front;
    self->front = self->front->next;
    free(pt);
    self->items--;
    if(self->items==0)
        self->rear = NULL;
    return (true);
}


