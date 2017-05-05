//
// Created by Nathan Pottorff on 4/24/17.
//

#include "writeBack.h"
#include "initalization.h"

void writeBack(instrFormat instr){

    switch(instr.opCode) {
        case 0x00:
            switch (instr.funct){
                case movn:
                    if(reg[instr.rt] != 0){
                        reg[instr.rd] = MEM_WB[0].exOutput;
                    }
                    break;
                case movz:
                    if(reg[instr.rt] == 0){
                        reg[instr.rd] = MEM_WB[0].exOutput;
                    }
                    break;
                default:
                    reg[instr.rd] = MEM_WB[0].exOutput;
                    break;


            }
            break;
        case addi:
            reg[instr.rt] = MEM_WB[0].exOutput;
            break;
        case addui:
            //cout << instr.rt << " = " << MEM_WB[0].exOutput << '\n';
            reg[instr.rt] = MEM_WB[0].exOutput;
            break;
        case andi:
            reg[instr.rt] = MEM_WB[0].exOutput;
            break;
        case xori:
            reg[instr.rt] = MEM_WB[0].exOutput;
            break;
        case ori:
            reg[instr.rt] = MEM_WB[0].exOutput;
            break;
        case slti:
            reg[instr.rt] = MEM_WB[0].exOutput;
            break;
        case sltiu:
            reg[instr.rt] = MEM_WB[0].exOutput;
            break;
        case sb:
            mainMemory[instr.exOutput] = MEM_WB[0].rt;
            break;
        case sh:
            mainMemory[instr.exOutput] = MEM_WB[0].rt;
            break;
        case sw:
            mainMemory[instr.exOutput] = MEM_WB[0].rt;
            break;
        case lb:
            reg[instr.rt] = instr.memOutput;
            break;
        case lbu:
            reg[instr.rt] = instr.memOutput;
            break;
        case lhu:
            reg[instr.rt] = instr.memOutput;
            break;
        case lui:
            reg[instr.rt] = instr.exOutput;
            break;
        case lw:
            reg[instr.rt] = instr.memOutput;
            break;
        case seb:
            reg[instr.rd] = MEM_WB[0].exOutput;
            break;
    }
    return;
}