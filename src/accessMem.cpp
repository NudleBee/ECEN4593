//
// Created by Nathan Pottorff on 4/24/17.
//

#include "accessMem.h"

int SB(int address, int pos, int rt){
    switch(pos) {
        case 0:
            return (mainMemory[address] & b0) | (reg[rt] & byte0);
        case 1:
            return (mainMemory[address] & b1) | (reg[rt] & byte1);
        case 2:
            return (mainMemory[address] & b2) | (reg[rt] & byte2);
        case 3:
            return (mainMemory[address] & b3) | (reg[rt] & byte3);
    }
    return 0;
}

int SH(int address, int pos, int rt){
    switch(pos) {
        case 0:
            return (mainMemory[address] & hwrd1) | (reg[rt] & hwrd0);
        case 1:
            return (mainMemory[address] & hwrd0) | (reg[rt] & hwrd1);
    }
    return 0;
}

int LB(int address, int pos, int rt){
    switch(pos) {
        case 0:
            return (reg[rt] & b0) | (mainMemory[address] & byte0);
        case 1:
            return (reg[rt] & b1) | (mainMemory[address] & byte1);
        case 2:
            return (reg[rt] & b2) | (mainMemory[address] & byte2);
        case 3:
            return (reg[rt] & b3) | (mainMemory[address] & byte3);
    }
    return 0;
}

int LBU(int address, int pos, int rt){
    switch(pos) {
        case 0:
            return (reg[rt] & b0) | (mainMemory[address] & byte0);
        case 1:
            return (reg[rt] & b1) | (mainMemory[address] & byte1);
        case 2:
            return (reg[rt] & b2) | (mainMemory[address] & byte2);
        case 3:
            return (reg[rt] & b3) | (mainMemory[address] & byte3);
    }
    return 0;
}

int LHU(int address, int pos, int rt){
    switch(pos) {
        case 0:
            return (mainMemory[address] & hwrd0) | (reg[rt] & hwrd1);
        case 1:
            return (mainMemory[address] & hwrd1) | (reg[rt] & hwrd0);
    }
    return 0;
}

void accessMem(instrFormat instr, int i) {
    MEM_WB[4] = EX_MEM[3];
    switch(instr.opCode) {
        case lb:
            MEM_WB[i].memOutput = LB(instr.exOutput, instr.pos, instr.rt);
            break;
        case lbu:
            MEM_WB[i].memOutput = LBU(instr.exOutput, instr.pos, instr.rt);
            break;
        case lhu:
            MEM_WB[i].memOutput = LHU(instr.exOutput, instr.pos, instr.rt);
            break;
        case lw:
            MEM_WB[i].memOutput = instr.exOutput;
            break;
        case sb:
            MEM_WB[i].memOutput = SB(instr.exOutput, instr.pos, instr.rt);
            break;
        case sh:
            MEM_WB[i].memOutput = SH(instr.exOutput, instr.pos, instr.rt);
            break;
        case sw:
            MEM_WB[i].memOutput = instr.exOutput;
            break;
    }
}