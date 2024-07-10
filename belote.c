#include "belote.h"

void initBelote(struct belote* b, void(*initGame)(void* b), void(*finaGame)(void* b), void(*runGame)(void* b), void* obj) {
    b->initGame = initGame;
    b->finaGame = finaGame;
    b->runGame = runGame;
    b->gameObj = obj;

    b->initGame(obj);
}
void finaBelote(struct belote* b) {
    if(b->finaGame == NULL)
        return;
    
    b->finaGame(b->gameObj);
}

void beloteRunGame(struct belote* b) {
    b->runGame(b->gameObj);
}

