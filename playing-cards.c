#include "playing-cards.h"
#include "random.h"

const char keyboardCards[][2] = {
    "as", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "0s", "js", "qs", "ks","ah", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "0h", "jh", "qh", "kh", "ad", "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "0d", "jd", "qd", "kd","ac", "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "0c", "jc", "qc", "kc",
};

const wchar_t unicodeCards[] = {
    L'🂡', L'🂢', L'🂣', L'🂤', L'🂥', L'🂦', L'🂧', L'🂨', L'🂩', L'🂪', L'🂫', L'🂭', L'🂮', L'🂱', L'🂲', L'🂳', L'🂴', L'🂵', L'🂶', L'🂷', L'🂸', L'🂹', L'🂺', L'🂻', L'🂽', L'🂾', L'🃁', L'🃂', L'🃃', L'🃄', L'🃅', L'🃆', L'🃇', L'🃈', L'🃉', L'🃊', L'🃋', L'🃍', L'🃎', L'🃑', L'🃒', L'🃓', L'🃔', L'🃕', L'🃖', L'🃗', L'🃘', L'🃙', L'🃚', L'🃛', L'🃝', L'🃞'
};

void resetDeck(cardDeck* d) {
    for(int i = 0; i < 52; i++)
        d->indices[i] = i;
}

void shuffleDeck(cardDeck* d) {
    for(int i = 0; i < 52; i++) {
        const int randIndice = randomInt(0, 51);
        const int swap = d->indices[i];
        d->indices[i] = d->indices[randIndice];
        d->indices[randIndice] = swap;
    }
}

wchar_t cardToUnicode(int c) {
    return unicodeCards[c];
}

const char* cardTokeyboard(int c) {
    return keyboardCards[c];
}

void printHand(cardDeck* d, int i) {
    printf("%lc  %lc  %lc  %lc", cardToUnicode(d->indices[(i<<2)]), cardToUnicode(d->indices[(i<<2)+1]), cardToUnicode(d->indices[(i<<2)+2]), cardToUnicode(d->indices[(i<<2)+3]));
}

