#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


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


typedef struct Node Node;
struct Node {
        int id;
        bool is_gateway;
        Node *adj; /* forms the adjacency linked list */
};


Node *newNode(int id) {
        Node *new = malloc(sizeof(Node));
        if (new == NULL) {
                return NULL;
        }

        new->id = id;
        new->adj = NULL;
        return new;
}


void add_link(Node **adj, int n1, int n2)
{
        Node *neighbor;

        if (!adj[n1]) {
                adj[n1] = newNode(n1);
        }

        neighbor = adj[n1];
        while(neighbor->adj != NULL) {
                neighbor = neighbor->adj;
        }

        neighbor->adj = newNode(n2);
}


int main()
{
        size_t node_count;
        int link_count, gateway_count, i;
        int n1, n2; /* a link from input */
        int gateway; /* a gateway from input */

        int crowding = 50; /* expect no more than this many links per node */
        Node **adjacency; /* the graph's adjacency list */
        bool *gateways; /* mark gateway nodes */

        Q *queue; /* search queue */
        int *parents; /* the parents of each node during a search */
        bool *visited; /* mark each node visited during search */
        Node *current; /* node during search */
        int current_id; /* node id during search */
        Node *neighbor;

        int skynet; /* Skynet agent position this turn */

        scanf("%lu%d%d", &node_count, &link_count, &gateway_count);

        adjacency = calloc(node_count, sizeof(Node*));

        for (i = 0; i < link_count; i++) {
                scanf("%d%d", &n1, &n2);
                add_link(adjacency, n1, n2);
                add_link(adjacency, n2, n1);
        }

        fprintf(stderr, "adjacency list:\n");
        for (i = 0; i < (int)node_count; i++) {
                fprintf(stderr, " %d -> ", i);
                current = adjacency[i]->adj;
                while (current != NULL) {
                        fprintf(stderr, "%d, ", current->id);
                        current = current->adj;
                }
                fprintf(stderr, "\n");
        }

        gateways = calloc(node_count, sizeof(bool));
        for (i = 0; i < gateway_count; i++) {
                scanf("%d", &gateway);
                fprintf(stderr, "marking gateway %d\n", gateway);
                gateways[gateway] = true;
        }

        /* game loop */
        while (1) {
                scanf("%d", &skynet);
                fprintf(stderr, "skynet = %d\n", skynet);

                queue = newQ(crowding);
                parents = calloc(node_count, sizeof(int));
                visited = calloc(node_count, sizeof(bool));

                enqueue(queue, skynet);
                while ((current_id = dequeue(queue)) != -1){
                        fprintf(stderr, "dequeued node %d\n", current_id);
                        current = adjacency[current_id];

                        if (gateways[current_id]) {
                                fprintf(stderr, "found gateway %d\n", current_id);
                                break;
                        }

                        if (visited[current_id]){
                                fprintf(stderr, "already visited %d\n", current_id);
                                continue;
                        }

                        fprintf(stderr, "getting neighbors of %d\n", current_id);

                        neighbor = current->adj;
                        while(neighbor != NULL) {
                                if (parents[neighbor->id] == -1){
                                        parents[neighbor->id] = current_id;
                                }
                                enqueue(queue, neighbor->id);
                                neighbor = neighbor->adj;
                        }
                        visited[current_id] = true;
                }

                printf("%d %d\n", current->id, parents[current->id]);
                return 0;
        }

        return 0;
}

/*
4 4 1
0 1
0 2
1 3
2 3
3

0
2

echo -e "4 4 1\n0 1\n\n0 2\n1 3\n2 3\n3\n0\n2\n" | ./graph

*/
