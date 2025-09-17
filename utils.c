#include <stdio.h>
#include "tournament.h"

// Return round name
const char* getRoundName(int round, int totalRounds) {
    if (round == totalRounds) return "Final";
    if (round == totalRounds - 1) return "Semifinal";
    if (round == totalRounds - 2) return "Quarterfinal";
    return "Round";
}
