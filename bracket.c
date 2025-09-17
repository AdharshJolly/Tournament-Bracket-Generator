#include <stdio.h>
#include "tournament.h"

// Display tree recursively (sideways)
void displayBracket(Node* root, int space) {
    if (root == NULL) return;

    space += SPACE;

    displayBracket(root->right, space);

    printf("\n");
    int i;
    for (i = SPACE; i < space; i++) printf(" ");
    printf("%s (%d)\n", root->name, root->score);

    displayBracket(root->left, space);
}

