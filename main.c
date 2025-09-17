#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tournament.h"

int main() {
    int choice, n, mode;
    Tournament* t = NULL;
    Node** players = NULL;

    srand(time(NULL)); // for random scores

    while (1) {
        printf("\n===== Tournament Menu =====\n");
        printf("1. Create Tournament\n");
        printf("2. Register Players\n");
        printf("3. Start Tournament\n");
        printf("4. Display Bracket\n");
        printf("5. Search Player\n");
        printf("6. Save Bracket to File\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter number of players (power of 2): ");
                if (scanf("%d", &n) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                t = createTournament(n);
                players = (Node**) malloc(n * sizeof(Node*));
                printf("Tournament created with %d players and %d rounds.\n", 
                        t->numPlayers, t->rounds);
                break;

            case 2:
                if (!t) { 
                    printf("Create a tournament first.\n"); 
                    break; 
                }
                registerPlayers(players, t->numPlayers);
                printf("Players registered successfully.\n");
                break;

            case 3:
                if (!t || !players) { 
                    printf("Register players first.\n"); 
                    break; 
                }

                printf("Choose Mode: 1 = Manual Scores | 2 = Random Simulation: ");
                if (scanf("%d", &mode) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }

                int round = 1;
                int totalRounds = t->rounds;
                int numMatches = t->numPlayers;

                Node** currentRound = players;
                Node** nextRound;

                while (numMatches > 1) {
                    printf("\n===== %s =====\n", getRoundName(round, totalRounds));
                    int nextSize = numMatches / 2;
                    nextRound = (Node**) malloc(nextSize * sizeof(Node*));
					
					int i;
                    for (i = 0; i < numMatches; i += 2) {
                        Node* winner = conductMatch(currentRound[i], currentRound[i+1], mode);
                        nextRound[i/2] = winner;

                        // Log match
                        logMatch(currentRound[i]->name, currentRound[i+1]->name,
                                 currentRound[i]->score, currentRound[i+1]->score,
                                 winner->name);
                    }

                    if (currentRound != players) {
                        free(currentRound); // free old round memory if dynamically allocated
                    }

                    currentRound = nextRound;
                    numMatches /= 2;
                    round++;
                }

                t->root = currentRound[0];
                printf("\nTournament Champion: %s\n", t->root->name);
                break;

            case 4:
                if (t && t->root) {
                    printf("\n===== Tournament Bracket =====\n");
                    displayBracket(t->root, 0);
                } else {
                    printf("No bracket yet.\n");
                }
                break;

            case 5:
                if (t && t->root) {
                    char name[NAME_LEN];
                    printf("Enter player name to search: ");
                    scanf("%s", name);
                    Node* result = searchPlayer(t->root, name);
                    if (result) printf("%s participated in the tournament.\n", name);
                    else printf("%s not found.\n", name);
                } else {
                    printf("Tournament not started.\n");
                }
                break;

            case 6:
                if (t && t->root) {
                    FILE *fp = fopen("bracket.txt", "w");
                    if (!fp) {
                        printf("Error saving bracket.\n");
                        break;
                    }
                    saveBracket(t->root, fp, 0);
                    fclose(fp);
                    printf("Bracket saved to bracket.txt\n");
                } else {
                    printf("No bracket to save.\n");
                }
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

