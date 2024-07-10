#include "reliableMemoryGame.h"
#include "terminalControl.h"
#include <stdio.h>

void initReliableMemoryGame(struct reliableMemoryGameData* b) {
    resetDeck(&b->deck);
    setlocale(LC_ALL, "");

    b->turns=0;
    b->dataFile = fopen("memory-practice.info", "r");
    if(b->dataFile) {
        fseek(b->dataFile, -3, SEEK_END);
        fscanf(b->dataFile, "%d", &b->turns);
        fclose(b->dataFile);
    }   
}

void runReliableMemoryGame(struct reliableMemoryGameData* b) {
    time_t start, end;

    struct terminalControl terminal;
    initTerminalControl(&terminal, 1);
    terminalControlCopyOriginal(&terminal);
    terminalControlParamOff(&terminal, 0, c_lflag, ECHO);
    terminalControlSwitchTermios(&terminal, 0);

    resetSeed();
    shuffleDeck(&b->deck);

    printf("Запамети взятките:\n🂠  🂠  🂠  🂠\n");
    getc(stdin);

    time(&start);
    for(int i = 0; i <= b->turns; i++) {
        printf("\x1B[0F");
        printHand(&b->deck, i); putchar('\n');

        getc(stdin);
    }
    printf("\x1B[0F🂠  🂠  🂠  🂠\n");
    time(&end);

    tcflush(0, TCIFLUSH);
    finaTerminalControl(&terminal);

    printf("Напиши последователността:\n");
    int i = 0;
    for(; i <= b->turns; i++) {
        char cardInput[4][2];
        scanf(" %s %s %s %s", cardInput[0], cardInput[1], cardInput[2], cardInput[3]);
        // remove trailing '\n'
        getc(stdin);

        for(int o = 0; o < 4; o++) {
            if(memcmp(cardInput[o], cardTokeyboard(b->deck.indices[(i<<2)+o]), 2)) {
                printf("Грешка!\n");
                
                printHand(&b->deck, i); putchar('\n');
                if(b->turns>0) {
                    b->turns--;
                }

                goto fail;
            }
        }
    }
    printf("Браво!\n");
    if(b->turns < 52/4) {
        b->turns++;
    }

    fail:;

    int deltaTime = end-start;
    struct tm* date = localtime(&start);

    char turnsStr[31];
    b->dataFile = fopen("memory-practice.info", "a");
    fwrite(turnsStr, 1, sprintf(turnsStr, "%.2d-%.2d-%.2d %.2d:%.2d:%2d %.2d %.4d %.2d\n", date->tm_year+1900, date->tm_mon + 1, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec, i, deltaTime, b->turns), b->dataFile);
    fclose(b->dataFile);
}


