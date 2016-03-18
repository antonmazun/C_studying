#include <stdio.h> //fprintf
#include <stdlib.h> //malloc free exit

#include "queue.h" //basic prototypes and 'define's

//private:
static void _CopyToNode(visitor_t visitor, node_t * pn)
{
    pn->visitor = visitor;
}
static void _CopyToItem(node_t * pn, visitor_t * visitor)
{
    *visitor = pn->visitor;
}

//public:
void queue_new(queue_t * self)
{
    self->front = self->rear = NULL;
    self->items = 0;
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
    _CopyToNode(visitor, pnew);
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
    _CopyToItem(self->front, visitor_deleted);
    pt = self->front;
    self->front = self->front->next;
    free(pt);
    self->items--;
    if(self->items==0)
        self->rear = NULL;
    return (true);
}


