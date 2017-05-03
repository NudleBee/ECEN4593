//
// Created by Nathan Pottorff on 4/24/17.
//

#include "writeBack.h"
#include "initalization.h"

void writeBack(instrFormat instr){
    switch(instr.opCode) {
        case 0x00:
            switch (instr.funct){
                case add:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case addu:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case and_f:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case nor:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case or_f:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case movn:
                    if(reg[instr.rt] != 0){
                        reg[instr.rd] = EX_MEM[4].exOutput;
                    }
                    break;
                case movz:
                    if(reg[instr.rt] == 0){
                        reg[instr.rd] = EX_MEM[4].exOutput;
                    }
                    break;
                case slt:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case sltu:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case sll:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case srl:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case sub:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case subu:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;
                case xor_f:
                    reg[instr.rd] = EX_MEM[4].exOutput;
                    break;

            }
            break;
        case addi:
            reg[instr.rt] = EX_MEM[4].exOutput;
            break;
        case addui:
            reg[instr.rt] = EX_MEM[4].exOutput;
            break;
        case andi:
            reg[instr.rt] = EX_MEM[4].exOutput;
            break;
        case xori:
            reg[instr.rt] = EX_MEM[4].exOutput;
            break;
        case ori:
            reg[instr.rt] = EX_MEM[4].exOutput;
            break;
        case slti:
            reg[instr.rt] = EX_MEM[4].exOutput;
            break;
        case sltiu:
            reg[instr.rt] = EX_MEM[4].exOutput;
            break;
        case sb:
            mainMemory[instr.exOutput] = instr.memOutput;
            break;
        case sh:
            mainMemory[instr.exOutput] = instr.memOutput;
            break;
        case sw:
            mainMemory[instr.exOutput] = instr.rt;
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
            EX_MEM[4].exOutput = signExtension(instr.imm | 0xFFFF);
            break;
        case lw:
            reg[instr.rt] = mainMemory[instr.exOutput];
            break;
        case seb:
            reg[instr.rd] = EX_MEM[4].exOutput;
            break;
    }
    return;
}