//
// Created by Nathan Pottorff on 4/25/17.
//
#include <iostream>
#include "cache.h"

using namespace std;

#ifndef ECEN4593_INITALIZATION_H
#define ECEN4593_INITALIZATION_H

struct instrFormat {
    int opCode = 0;
    int rs = 0;
    int rt = 0;
    int rd = 0;
    int shamt = 0;
    int funct = 0;
    int imm = 0;
    int address = 0;
    int exOutput = 0;
    int pos = 0;
    int memOutput = 0;
};

unsigned int mainMemory[1200] = {0};
int reg[32];
int sp, fp, pc;
int cycleCount, CPI, Ihit, Dhit;
bool stall = false;

int IF_ID[4] = {0};
instrFormat ID_EX[4];
instrFormat EX_MEM[4];
instrFormat MEM_WB[4];

int readFile(string fileName);

void shadowShift();

void printMem();

#endif //ECEN4593_INITALIZATION_H
