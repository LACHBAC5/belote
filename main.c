#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "belote.h"
#include "reliableMemoryGame.h"
#include "rapidMemoryGame.h"

int main() {
    struct belote game;

    char gameData[512];
    char input[64];

    printf("Избери игра: ");
    while(1) {
        scanf("%s", input);
        if(strcmp(input, "remg")==0) {
            initBelote(&game, initReliableMemoryGame, NULL, runReliableMemoryGame, gameData);
            break;
        }
        else if (strcmp(input, "ramg")==0) {
            initBelote(&game, initRapidMemoryGame, NULL, runRapidMemoryGame, gameData);
            break;
        }
        printf("\x1B[0FИзбери игра: ");
    }
    // remove trailing '\n'
    getc(stdin);

    do {
        beloteRunGame(&game);
        printf("\nВъведи q за излизане... ");
    }
    while(getc(stdin) != 'q');
    
    finaBelote(&game);
}
