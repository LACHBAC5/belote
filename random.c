#include "random.h"

void resetSeed() {
    srand(clock());
}

int randomInt(int min, int max) {
    return rand() % ( max-min+1 ) + min;
}
