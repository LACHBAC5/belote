#pragma once
#include <wchar.h>
#include <stdio.h>
#include "random.h"

extern const wchar_t unicodeCards[];
extern const char keyboardCards[][2];

typedef struct d {
    unsigned short indices[52];
} cardDeck;

void resetDeck(cardDeck* d);
void shuffleDeck(cardDeck* d);

wchar_t cardToUnicode(int c);
const char* cardTokeyboard(int c);

void printHand(cardDeck* d, int i);
