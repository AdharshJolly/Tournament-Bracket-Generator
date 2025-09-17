#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tournament.h"

// Register players into array
void registerPlayers(Node* players[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        char name[NAME_LEN];
        printf("Enter name of Player %d: ", i + 1);
        scanf("%s", name);
        players[i] = createNode(name);
    }
}

// Search player in tree
Node* searchPlayer(Node* root, char *name) {
    if (root == NULL) return NULL;
    if (strcmp(root->name, name) == 0) return root;

    Node* leftResult = searchPlayer(root->left, name);
    if (leftResult) return leftResult;

    return searchPlayer(root->right, name);
}

