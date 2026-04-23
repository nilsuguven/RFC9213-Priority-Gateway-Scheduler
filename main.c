#include <stdio.h>
#include <string.h>
#include "priority_queue.h"

int parseRFC9213(char *header) {
    char *p = strstr(header, "u=");
    if (p) return p[2] - '0';
    return 3;
}

int main() {
    PriorityQueue *pq = createQueue(10);
    char *inputs[] = {"u=5", "u=0", "u=3", "u=1"};
    char *desc[] = {"Background Data", "CRITICAL ERROR", "Normal Request", "User Login"};

    for(int i = 0; i < 4; i++) {
        Request req;
        req.id = i + 1;
        req.urgency = parseRFC9213(inputs[i]);
        strcpy(req.data, desc[i]);
        insert(pq, req);
    }

    printf("API Gateway Isleme Sirasi:\n");
    while(pq->size > 0) {
        Request top = extractMin(pq);
        printf("[ID: %d] [Urgency: %d] -> %s\n", top.id, top.urgency, top.data);
    }

    freeQueue(pq);
    return 0;
}