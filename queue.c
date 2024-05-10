#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void node_init(Node *n, int data) {
    n->data = data;
    n->next = NULL;
}

void node_free(Node *n) {
    n->next = NULL;
}

void node_set_data(Node *n, int data) {
    n->data = data;
}

int node_get_data(Node *n) {
    return n->data;
}

void node_set_next(Node *n, Node *next) {
    n->next = next;
}

void queue_init(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void queue_free(Queue *q) {
    Node *current = q->front;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        node_free(current);
        current = next;
    }

    q->front = NULL;
    q->rear = NULL;
}

void queue_enqueue(Queue *q, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    node_init(new_node, data);

    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        node_set_next(q->rear, new_node);
        q->rear = new_node;
    }
}

int queue_dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1;
    }

    Node *front = q->front;
    int data = node_get_data(front);

    q->front = front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(front);

    return data;
}

int queue_front(Queue *q) {
    if (q->front == NULL) {
        return -1;
    }

    return node_get_data(q->front);
}

int queue_rear(Queue *q) {
    if (q->rear == NULL) {
        return -1;
    }

    return node_get_data(q->rear);
}

bool queue_is_empty(Queue *q) {
    return q->front == NULL;
}

void queue_print(Queue *q) {
    Node *current = q->front;
    printf("Queue: \n");

    while (current != NULL) {
        printf("%d ", node_get_data(current));
        current = current->next;
    }

    printf("\n");
}