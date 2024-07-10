#pragma once

#include <termios.h>
#include <unistd.h>
#include "array.h"

struct terminalControl {
    array states;
};

enum termiosFlags {c_iflag, c_oflag, c_cflag, c_lflag, c_cc};

void initTerminalControl(struct terminalControl* t, int states);
void finaTerminalControl(struct terminalControl* t);

void terminalControlParamOn(struct terminalControl* t, int indice, enum termiosFlags flag, tcflag_t param);
void terminalControlParamOff(struct terminalControl* t, int indice, enum termiosFlags flag, tcflag_t param);

void terminalControlCopyOriginal(struct terminalControl* t);
void terminalControlCopyTermios(struct terminalControl* t, int indice);
void terminalControlSwitchTermios(struct terminalControl* t, int indice);
