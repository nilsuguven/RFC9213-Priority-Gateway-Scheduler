#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "types.h"

PriorityQueue* createQueue(int capacity);
void insert(PriorityQueue *pq, Request req);
Request extractMin(PriorityQueue *pq);
void freeQueue(PriorityQueue *pq);

#endif