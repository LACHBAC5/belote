#pragma once
#include <stdlib.h>
#include <locale.h>
#include <termios.h>
#include <string.h>
#include "playing-cards.h"

struct reliableMemoryGameData {
    int turns;
    FILE* dataFile;
    cardDeck deck;
};

void initReliableMemoryGame(struct reliableMemoryGameData* b);
void finaReliableMemoryGame(struct reliableMemoryGameData* b);

void runReliableMemoryGame(struct reliableMemoryGameData* b);
