#include "terminalControl.h"
#include "array.h"
#include <termios.h>

void initTerminalControl(struct terminalControl* t, int states) {
    initArray(&t->states, ++states, sizeof(struct termios));
    tcgetattr(0, arrayAt(&t->states, 0)); t->states.length++;
}
void finaTerminalControl(struct terminalControl* t) {
    terminalControlSwitchTermios(t, -1);
    finaArray(&t->states);
}

void terminalControlParamOn(struct terminalControl* t, int indice, enum termiosFlags flag, tcflag_t param) {
    *((tcflag_t*)arrayAt(&t->states, ++indice)+flag) |= param;
}
void terminalControlParamOff(struct terminalControl* t, int indice, enum termiosFlags flag, tcflag_t param) {
    *((tcflag_t*)arrayAt(&t->states, ++indice)+flag) &= ~param;
}

void terminalControlCopyOriginal(struct terminalControl* t) {
    terminalControlCopyTermios(t, -1);
}

void terminalControlCopyTermios(struct terminalControl* t, int indice) {
    struct termios temp = *(struct termios*)arrayAt(&t->states, ++indice);
    arrayPushBack(&t->states, &temp);
}

void terminalControlSwitchTermios(struct terminalControl* t, int indice) {
    tcsetattr(0, TCSANOW, arrayAt(&t->states, ++indice));
}
