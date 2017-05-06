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

void accessMem(instrFormat instr) {
    switch (instr.opCode) {
        case 0x0:
            switch (instr.funct){
                case add:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case addu:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case and_f:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case nor:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case or_f:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case movn:
                    if(reg[instr.rt] != 0) {
                        MEM_WB[1].memOutput = instr.exOutput;
                    }
                    break;
                case movz:
                    if(reg[instr.rt] == 0) {
                        MEM_WB[1].memOutput = instr.exOutput;
                    }
                    break;
                case slt:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case sltu:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case sll:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case srl:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case sub:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case subu:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case xor_f:
                    MEM_WB[1].memOutput = instr.exOutput;
                    break;
                case jr:
                    //cout << "jr" << " " << reg[instr.rs] << '\n';
                    break;
            }
            break;
        case addi:
            MEM_WB[1].memOutput = instr.exOutput;
            break;
        case addiu:
            MEM_WB[1].memOutput = instr.exOutput;
            break;
        case andi:
            MEM_WB[1].memOutput = instr.exOutput;
            break;
        case xori:
            MEM_WB[1].memOutput = instr.exOutput;
            break;
        case ori:
            MEM_WB[1].memOutput = instr.exOutput;
            break;
        case slti:
            MEM_WB[1].memOutput = instr.exOutput;
            break;
        case sltiu:
            MEM_WB[1].memOutput = instr.exOutput;
            break;
        case lb:
            MEM_WB[1].memOutput = LB(instr.exOutput, instr.pos, instr.rt);
            break;
        case lbu:
            MEM_WB[1].memOutput = LBU(instr.exOutput, instr.pos, instr.rt);
            break;
        case lhu:
            MEM_WB[1].memOutput = LHU(instr.exOutput, instr.pos, instr.rt);
            break;
        case lw:
            MEM_WB[1].memOutput = mainMemory[instr.exOutput];
            break;
        case sb:
            MEM_WB[1].memOutput = SB(instr.exOutput, instr.pos, instr.rt);
            break;
        case sh:
            MEM_WB[1].memOutput = SH(instr.exOutput, instr.pos, instr.rt);
            break;
        case sw:
            MEM_WB[1].memOutput = mainMemory[instr.exOutput];
            break;
    }

    //Memory to Memory copies
    switch (EX_MEM[1].opCode) {
        case sw:
            switch (MEM_WB[1].opCode) {
                case lw:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lb:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lbu:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lhu:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
            }
            break;
        case sh:
            switch (MEM_WB[1].opCode) {
                case lw:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lb:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lbu:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lhu:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
            }
            break;
        case sb:
            switch (MEM_WB[1].opCode) {
                case lw:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lb:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lbu:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
                case lhu:
                    if (EX_MEM[1].rt == MEM_WB[1].rt) {
                        cout << "MEM to MEM copy" << '\n';
                        MEM_WB[1].memOutput = EX_MEM[1].exOutput;
                    }
                    break;
            }
            break;
    }



}