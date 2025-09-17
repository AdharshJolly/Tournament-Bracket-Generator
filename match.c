#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tournament.h"

// Create a new player node
Node* createNode(char *name) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->name, name);
    node->score = 0;
    node->left = node->right = NULL;
    return node;
}

// Conduct a match between two players
Node* conductMatch(Node* p1, Node* p2, int mode) {
    if (!p1 || !p2) return p1 ? p1 : p2;

    printf("\nMatch: %s vs %s\n", p1->name, p2->name);

    if (mode == 1) {  // Manual Scores
        printf("Enter score for %s: ", p1->name);
        scanf("%d", &p1->score);
        printf("Enter score for %s: ", p2->name);
        scanf("%d", &p2->score);
    } else {  // Random Mode
        p1->score = rand() % 10;
        p2->score = rand() % 10;
        printf("Random scores: %s(%d) - %s(%d)\n", p1->name, p1->score, p2->name, p2->score);
    }

    Node* winner = (p1->score >= p2->score) ? p1 : p2;
    printf("Winner: %s\n", winner->name);

    Node* matchNode = createNode(winner->name);
    matchNode->left = p1;
    matchNode->right = p2;

    return matchNode;
}
