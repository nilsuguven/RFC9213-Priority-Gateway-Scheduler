#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

PriorityQueue* createQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->heap = (Request*)malloc(sizeof(Request) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(Request *a, Request *b) {
    Request temp = *a;
    *a = *b;
    *b = temp;
}

void insert(PriorityQueue *pq, Request req) {
    if (pq->size == pq->capacity) return;
    int i = pq->size++;
    pq->heap[i] = req;
    while (i != 0 && pq->heap[(i - 1) / 2].urgency > pq->heap[i].urgency) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Request extractMin(PriorityQueue *pq) {
    Request root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int smallest = 2 * i + 1;
        if (2 * i + 2 < pq->size && pq->heap[2 * i + 2].urgency < pq->heap[smallest].urgency)
            smallest = 2 * i + 2;
        if (pq->heap[i].urgency <= pq->heap[smallest].urgency) break;
        swap(&pq->heap[i], &pq->heap[smallest]);
        i = smallest;
    }
    return root;
}

void freeQueue(PriorityQueue *pq) {
    free(pq->heap);
    free(pq);
}