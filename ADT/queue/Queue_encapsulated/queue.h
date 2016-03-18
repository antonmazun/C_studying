#pragma once
#include <stdbool.h> //boolean type
#define MAXQUEUE 10

/* Structure to describe visitor.
    Fields:
    long arrive;
    int processtime;
*/
//typedef struct visitor_s visitor_t;

//Test typedef
typedef int visitor_t;

/* Node type.
    Fields:
    visitor_t visitor;
    struct node_s * next;
*/
typedef struct node_s node_t;

/* Queue ADT.
    Fields:
    node_t *front
    node_t *rear
    int items
*/
typedef struct queue_s queue_t;

// Constructor.
queue_t * queue_new();
// Destructor.
void queue_delete(queue_t * self);
// Essential helping functions.
bool queue_isFull(const queue_t * self);
bool queue_isEmpty(const queue_t * self);
int queue_itemCount(const queue_t * self);
// Adding an item to the queue.
bool queue_enqueue(visitor_t visitor, queue_t * self);
// Deleting an item from the queue.
bool queue_dequeue(visitor_t * visitor_deleted, queue_t * self);
