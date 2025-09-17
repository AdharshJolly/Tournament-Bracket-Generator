#include <stdio.h>
#include "tournament.h"

// Save tree in preorder (for logs)
void saveBracket(Node* root, FILE *fp, int depth) {
    if (!root) return;
    int i;
    for (i = 0; i < depth; i++) fprintf(fp, "  ");
    fprintf(fp, "%s (%d)\n", root->name, root->score);

    saveBracket(root->left, fp, depth + 1);
    saveBracket(root->right, fp, depth + 1);
}

// Log match results
void logMatch(char *player1, char *player2, int score1, int score2, char *winner) {
    FILE *fp = fopen("tournament_log.txt", "a");
    if (!fp) return;

    fprintf(fp, "%s (%d) vs %s (%d) -> Winner: %s\n",
            player1, score1, player2, score2, winner);
    fclose(fp);
}

