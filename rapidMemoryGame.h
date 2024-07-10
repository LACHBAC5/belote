#pragma once
#include <stdlib.h>
#include <locale.h>
#include <termios.h>
#include <string.h>
#include "playing-cards.h"
#include "terminalControl.h"

struct rapidMemoryGame {
    cardDeck deck;
};

void initRapidMemoryGame(struct rapidMemoryGame* b);
void finaRapidMemoryGame(struct rapidMemoryGame* b);

void runRapidMemoryGame(struct rapidMemoryGame* b);
