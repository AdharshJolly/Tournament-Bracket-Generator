#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tournament.h"

// Create a tournament with given number of players
Tournament* createTournament(int n) {
    Tournament* t = (Tournament*) malloc(sizeof(Tournament));
    t->numPlayers = n;
    t->rounds = calculateRounds(n);
    t->root = NULL;
    return t;
}

// Calculate rounds needed (log2(n))
int calculateRounds(int n) {
    int rounds = 0;
    while (n > 1) {
        n /= 2;
        rounds++;
    }
    return rounds;
}

int nextPowerOf2(int n) {
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}
