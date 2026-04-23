#ifndef TYPES_H
#define TYPES_H

typedef struct {
    int id;
    int urgency;   // RFC 9213: 0 (en yüksek) - 7 (en düşük)
    char data[256];
} Request;

typedef struct {
    Request *heap;
    int size;
    int capacity;
} PriorityQueue;

#endif