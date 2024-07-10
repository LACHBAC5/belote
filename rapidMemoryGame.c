#include "rapidMemoryGame.h"
#include "terminalControl.h"
#include <stdio.h>

void initRapidMemoryGame(struct rapidMemoryGame* b) {
    resetDeck(&b->deck);
    setlocale(LC_ALL, "");
}

void runRapidMemoryGame(struct rapidMemoryGame* b) {
    time_t start, end;

    struct terminalControl terminal;
    initTerminalControl(&terminal, 1);
    terminalControlCopyOriginal(&terminal);
    terminalControlParamOff(&terminal, 0, c_lflag, ECHO | ICANON);
    terminalControlSwitchTermios(&terminal, 0);

    resetSeed();
    shuffleDeck(&b->deck);

    int successes=0;
    char cardInput[4][2];
    printf("Запамети взятката:\n🂠  🂠  🂠  🂠\n");
    getc(stdin);
    time(&start);
    for(int i = 0; i < 5; i++) {
        printf("\x1B[1F");
        printHand(&b->deck, i); putchar('\n');
        getc(stdin);
        printf("\x1B[1F🂠  🂠  🂠  🂠\n");

        terminalControlSwitchTermios(&terminal, -1);
        scanf(" %s %s %s %s", cardInput[0], cardInput[1], cardInput[2], cardInput[3]);
        terminalControlSwitchTermios(&terminal, 0);
        while(getchar() != '\n') {}

        printf("\x1B[1F\x1B[2K");

        for(int o = 0; o < 4; o++) {
            int fail = memcmp(cardInput[o], cardTokeyboard(b->deck.indices[(i<<2)+o]), 2);
            if(fail) {
                printf("Грешка! ");
                printHand(&b->deck, i);
                getc(stdin);
                printf("\x1B[2K");
                
                goto fail;
            }
        }
        successes++;
        fail:;
    }
    time(&end);

    tcflush(0, TCIFLUSH);
    finaTerminalControl(&terminal);

    int deltaTime = end-start;
    struct tm* date = localtime(&start);

    char entryStr[40];
    FILE* dataFile = fopen("rapid-memory-practice.info", "a");
    fwrite(entryStr, 1, sprintf(entryStr, "%.4d-%.2d-%.2d %.2d:%.2d:%2d %.1d %.4d\n", date->tm_year+1900, date->tm_mon + 1, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec, successes, deltaTime), dataFile);
    fclose(dataFile);
}
