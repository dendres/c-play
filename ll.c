#include <stdio.h>
#include <stdlib.h>

/*
try out a linked list
*/

typedef struct Node Node;

struct Node {
        int id;
        Node *adj;
};

Node *newNode() {
        Node *new = malloc(sizeof(Node));
        if (new == NULL) {
                return NULL;
        }

        new->id = 0;
        new->adj = NULL;
        return new;
}

int main()
{
        Node *head, *current;

        int input[5] = {10,11,12,13,14};
        int i;

        head = newNode();

        current = head;
        for (i = 0; i < 5; i++) {
                current->id = input[i];

                if (i < 4) {
                        current->adj = newNode();
                        current = current->adj;
                }
        }

        current = head;
        while (current != NULL) {
                printf("node id = %d\n", current->id);
                current = current->adj;
        }

        return 0;
}
