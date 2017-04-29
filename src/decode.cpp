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
                case add: cout << "add" << '\n';
                    reg[instr.rd] = ADD(reg[instr.rs], reg[instr.rt]);
                    break;
                case addu: cout << "addu" << '\n';
                    reg[instr.rd] = ADDU(reg[instr.rs], reg[instr.rt]);
                    break;
                case and_f: cout << "and_f" << '\n';
                    reg[instr.rd] = AND_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case nor: cout << "nor" << '\n';
                    reg[instr.rd] = NOR(reg[instr.rs], reg[instr.rt]);
                    break;
                case or_f: cout << "or_f" << '\n';
                    reg[instr.rd] = OR_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case movn: cout << "movn" << '\n';
                    if(reg[instr.rt] != 0){
                        reg[instr.rd] = reg[instr.rs];
                    }
                    break;
                case movz: cout << "movz" << '\n';
                    if(reg[instr.rt] == 0){
                        reg[instr.rd] = reg[instr.rs];
                    }
                    break;
                case slt: cout << "slt" << '\n';
                    reg[instr.rd] = SLT(reg[instr.rs], reg[instr.rt]);
                    break;
                case sltu: cout << "sltu" << '\n';
                    reg[instr.rd] = SLTU(reg[instr.rs], reg[instr.rt]);
                    break;
                case sll: cout << "sll" << '\n';
                    reg[instr.rd] = SLL(reg[instr.rt], instr.shamt);
                    break;
                case srl: cout << "srl" << '\n';
                    reg[instr.rd] = SRL(reg[instr.rt], instr.shamt);
                    break;
                case sub: cout << "sub" << '\n';
                    reg[instr.rd] = SUB(reg[instr.rs], reg[instr.rt]);
                    break;
                case subu: cout << "subu" << '\n';
                    reg[instr.rd] = SUBU(reg[instr.rs], reg[instr.rt]);
                    break;
                case xor_f: cout << "xor_f" << '\n';
                    reg[instr.rd] = XOR_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case jr: cout << "jr" << '\n';
                    return reg[instr.rs];
            }
            break;
        case addi: cout << "addi" << '\n';
            reg[instr.rt] = ADDI(reg[instr.rs], instr.imm);
            break;
        case addui: cout << "addui" << '\n';
            reg[instr.rt] = ADDUI(reg[instr.rs], instr.imm);
            break;
        case andi: cout << "andi" << '\n';
            reg[instr.rt] = ANDI(reg[instr.rs], instr.imm);
            break;
        case xori: cout << "xori" << '\n';
            reg[instr.rt] = XORI(reg[instr.rs], instr.imm);
            break;
        case beq: cout << "beq" << '\n';
            if(BEQ(reg[instr.rs], reg[instr.rt])){
                return instr.imm;
            }
            break;
        case bne: cout << "bne" << '\n';
            if(BNE(reg[instr.rs], reg[instr.rt])){
                return instr.imm;
            }
            break;
        case bgtz: cout << "bgtz" << '\n';
            if(BGTZ(reg[instr.rs])){
                return instr.imm;
            }
            break;
        case bltz: cout << "bltz" << '\n';
            if(BLTZ(reg[instr.rs])){
                return instr.imm;
            }
            break;
        case blez: cout << "blez" << '\n';
            if(BLEZ(reg[instr.rs])){
                return instr.imm;
            }
            break;
        case j: cout << "j" << '\n';
            return instr.address;
        case jal: cout << "jal" << '\n';
            break;
        case lb: cout << "lb" << '\n';
            break;
        case lbu: cout << "lbu" << '\n';
            break;
        case lhu: cout << "lhu" << '\n';
            break;
        case lui: cout << "lui" << '\n';
            break;
        case lw: cout << "lw" << '\n';
            break;
        case ori: cout << "ori" << '\n';
            break;
        case slti: cout << "stli" << '\n';
            reg[instr.rt] = SLTI(reg[instr.rs], instr.imm);
            break;
        case sltiu: cout << "sltiu" << '\n';
            break;
        case sb: cout << "sb" << '\n';
            break;
        case sh: cout << "sh" << '\n';
            break;
        case sw: cout << "sw" << '\n';
            break;
        case seb: cout << "seb" << '\n';
            break;
    }


    return 0;
}