#pragma once

#include <stdbool.h>

#define NAMESIZE 45

typedef struct customer_s
{
    char name[NAMESIZE];
    int money;
} Item; //Item - thing for list ADT.

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef Node *List;

void InitializeList(List *plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned ListItemCount(const List *plist);
bool AddItem(Item item, List *plist);
void Traverse(const List *pList, void (* pfun)(Item item));
void DeleteList(Linst *plist);
