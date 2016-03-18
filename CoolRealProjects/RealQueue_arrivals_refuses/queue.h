#pragma once
#include <stdbool.h> //boolean type
#define MAXQUEUE 20

typedef struct visitor_s {
    long arrive;
    int processtime;
} visitor_t;

typedef struct node_s {
    visitor_t visitor;
    struct node_s * next;
} node_t;

typedef struct queue_s {
    node_t * front;
    node_t * rear;
    int items;
} queue_t;

// Constructor.
void queue_new(queue_t * self);
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
