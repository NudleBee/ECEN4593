//
// Created by Nathan Pottorff on 4/24/17.
//

#include "decode.h"
#include "fetch.h"
#include "execute.cpp"

using namespace std;

//Branch Detection (update pc)

int reg[32] = {0};

int decode(instFormat instr){
    switch(instr.opCode) {
        case 0x00:
            switch (instr.funct){
                case add: reg[instr.rd] = ADD(reg[instr.rs], reg[instr.rt]);
                    break;
                case addu: reg[instr.rd] = ADDU(reg[instr.rs], reg[instr.rt]);
                    break;
                case and_f: reg[instr.rd] = AND_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case nor: reg[instr.rd] = NOR(reg[instr.rs], reg[instr.rt]);
                    break;
                case or_f: reg[instr.rd] = OR_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case movn: if(reg[instr.rt] != 0){
                        reg[instr.rd] = reg[instr.rs];
                    }
                    break;
                case movz: if(reg[instr.rt] == 0){
                        reg[instr.rd] = reg[instr.rs];
                    }
                    break;
                case slt: reg[instr.rd] = SLT(reg[instr.rs], reg[instr.rt]);
                    break;
                case sltu: reg[instr.rd] = SLTU(reg[instr.rs], reg[instr.rt]);
                    break;
                case sll: reg[instr.rd] = SLL(reg[instr.rt], instr.shamt);
                    break;
                case srl: reg[instr.rd] = SRL(reg[instr.rt], instr.shamt);
                    break;
                case sub: reg[instr.rd] = SUB(reg[instr.rs], reg[instr.rt]);
                    break;
                case subu: reg[instr.rd] = SUBU(reg[instr.rs], reg[instr.rt]);
                    break;
                case xor_f: reg[instr.rd] = XOR_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case jr: return reg[instr.rs];
            }
            break;
        case addi: reg[instr.rt] = ADDI(reg[instr.rs], instr.imm);
            break;
        case addui: reg[instr.rt] = ADDUI(reg[instr.rs], instr.imm);
            break;
        case andi: reg[instr.rt] = ANDI(reg[instr.rs], instr.imm);
            break;
        case xori: reg[instr.rt] = XORI(reg[instr.rs], instr.imm);
            break;
        case beq: if(BEQ(reg[instr.rs], reg[instr.rt])){
                return instr.imm;
            }
            break;
        case bne: if(BNE(reg[instr.rs], reg[instr.rt])){
                return instr.imm;
            }
            break;
        case bgtz: if(BGTZ(reg[instr.rs])){
                return instr.imm;
            }
            break;
        case bltz: if(BLTZ(reg[instr.rs])){
                return instr.imm;
            }
            break;
        case blez: if(BLEZ(reg[instr.rs])){
                return instr.imm;
            }
            break;
        case j: return instr.address;
        case jal:
            break;
        case lb:
            break;
        case lbu:
            break;
        case lhu:
            break;
        case lui:
            break;
        case lw:
            break;
        case ori:
            break;
        case slti:
            break;
        case sltiu:
            break;
        case sb:
            break;
        case sh:
            break;
        case sw:
            break;
        case seb:
            break;
    }


    return 0;
}