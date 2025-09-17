#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#define NAME_LEN 50
#define SPACE 12

// Structures
typedef struct Node {
    char name[NAME_LEN];
    int score;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tournament {
    int numPlayers;
    int rounds;
    Node* root;
} Tournament;


// Function Declarations

// tournament.c
Tournament* createTournament(int n);
int calculateRounds(int n);

// match.c
Node* conductMatch(Node* p1, Node* p2, int mode);
Node* createNode(char *name);

// bracket.c
void displayBracket(Node* root, int space);

// player.c
void registerPlayers(Node* players[], int n);
Node* searchPlayer(Node* root, char *name);

// fileio.c
void saveBracket(Node* root, FILE *fp, int depth);
void logMatch(char *player1, char *player2, int score1, int score2, char *winner);

// utils.c
const char* getRoundName(int round, int totalRounds);

#endif

