//
// Created by Nathan Pottorff on 4/25/17.
//
#include <iostream>

using namespace std;

#ifndef ECEN4593_INITALIZATION_H
#define ECEN4593_INITALIZATION_H

struct instrFormat {
    int opCode;
    int rs;
    int rt;
    int rd;
    int shamt;
    int funct;
    int imm;
    int address;
    int exOutput;
    int pos;
    int memOutput;
};

int instrMem[500];
int mainMemory[1200] = {0};
int reg[32];
int sp, fp, pc;
int clk, CPI, *Ihit, Dhit;

int IF_ID[5];
instrFormat ID_EX[5];
instrFormat EX_MEM[5];
instrFormat MEM_WB[5];

int readFile(string fileName);

void shadowShift();

#endif //ECEN4593_INITALIZATION_H
