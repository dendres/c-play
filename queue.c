#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* a circular buffer of positive int */

typedef struct Q Q;

struct Q {
        int *list;
        int size;
        int head;
        int tail;
};


Q *newQ(int size) {
        Q *new = malloc(sizeof(Q));

        new->list = calloc((size_t)size, sizeof(int));
        new->size = size;
        new->head = 0;
        new->tail = 0;
        return new;
}


/* return false if the queue is full */
bool enqueue(Q *q, int id)
{
        int next_tail = (q->tail + 1) % q->size;
        if (next_tail == q->head) {
                return false;
        }
        q->list[q->tail] = id;
        q->tail = next_tail;
        return true;
}


/* return -1 if empty */
int dequeue(Q *q)
{
        int id;

        if (q->tail == q->head) {
                return -1;
        }
        id = q->list[q->head];
        q->list[q->head] = -1;
        q->head = (q->head + 1) % q->size;
        return id;
}


void printq(Q *q) {
        int i;

        for(i = 0; i < q->size; i++) {
                printf("%d%c", q->list[i], (i < (q->size -1) ? ',' : '\n'));
        }
}


int main()
{
        Q *queue = newQ(5);
        int out;

        if (!enqueue(queue, 10)) printf("queue is full\n"); printq(queue);
        if (!enqueue(queue, 11)) printf("queue is full\n"); printq(queue);
        if (!enqueue(queue, 12)) printf("queue is full\n"); printq(queue);
        out = dequeue(queue); printf("got %d\n", out); printq(queue);
        out = dequeue(queue); printf("got %d\n", out); printq(queue);
        out = dequeue(queue); printf("got %d\n", out); printq(queue);
        out = dequeue(queue); printf("got %d\n", out); printq(queue);
        out = dequeue(queue); printf("got %d\n", out); printq(queue);
        out = dequeue(queue); printf("got %d\n", out); printq(queue);
        out = dequeue(queue); printf("got %d\n", out); printq(queue);
        out = dequeue(queue); printf("got %d\n", out); printq(queue);
        if (!enqueue(queue, 13)) printf("queue is full\n"); printq(queue);
        if (!enqueue(queue, 14)) printf("queue is full\n"); printq(queue);
        if (!enqueue(queue, 15)) printf("queue is full\n"); printq(queue);
        if (!enqueue(queue, 16)) printf("queue is full\n"); printq(queue);
        if (!enqueue(queue, 17)) printf("queue is full\n"); printq(queue);

        return 0;
}
