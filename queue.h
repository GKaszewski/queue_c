#ifndef _QUEUE_H
#define _QUEUE_H

#include "stdio.h"
#include <stdbool.h>

// TODO for the future: make this a generic queue (HINT: use void* data)

typedef struct node {
    int data;
    struct node* next;
} Node;

void node_set_data(Node* n, int data);
int node_get_data(Node* n);

void node_set_next(Node* n, Node* next);

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

void queue_init(Queue* q);
void queue_free(Queue* q);

void queue_enqueue(Queue* q, int data);
int queue_dequeue(Queue* q);
int queue_front(Queue* q);
int queue_rear(Queue* q);
bool queue_is_empty(Queue* q);
void queue_print(Queue* q);

#endif