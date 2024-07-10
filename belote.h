#pragma once
#include <locale.h>
#include "playing-cards.h"
#include "terminalControl.h"
#include <stdio.h>

struct belote {
    void (*initGame)(void* b);
    void (*finaGame)(void* b);
    void (*runGame)(void* b);
    void* gameObj;
};

void initBelote(struct belote* b, void(*initGame)(void* b), void(*finaGame)(void* b), void(*runGame)(void* b), void* obj);
void finaBelote(struct belote* b);

void beloteRunGame(struct belote* b);
