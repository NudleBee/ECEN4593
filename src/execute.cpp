//
// Created by Nathan Pottorff on 4/24/17.
//

#include "execute.h"

int ADD(int rs, int rt){
    return reg[rs] + reg[rt];
}

int ADDU(int rs, int rt){
    return rs + rt;
}

int AND_F(int rs, int rt){
    return rs & rt;
}

int NOR(int rs, int rt){
    return ~(rs|rt);
}

int OR_F(int rs, int rt){
    return rs | rt;

}

int SLT(int rs, int rt){
    if(rs < rt){
        return 1;
    }
    return 0;
}

int SLTU(int rs, int rt){
    if (rs < rt){
        return 1;
    }
    return 0;
}

int SLL(int rt, int shamt){
    return (rt << shamt);
}

int SRL(int rt, int shamt){
    return (rt >> shamt);
}

int SUB(int rs, int rt){
    return rs - rt;
}

int SUBU(int rs, int rt){
    return rs - rt;
}

int XOR_F(int rs, int rt){
    return rs^rt;
}

int ADDI(int rs, int imm){
    return rs + imm;
}

int ADDIU(int rs, int imm){
    return rs + imm;
}

int ANDI(int rs, int imm){
    return rs & imm;
}

int XORI(int rs, int imm){
    return rs^imm;
}



int ORI(int rs, int imm){
    return rs | imm;
}

int SLTI(int rs, int imm){
    if(rs < imm){
        return 1;
    }
    return 0;
}

int SLTIU(int rs, int imm){
    if(rs < imm){
        return 1;
    }
    return 0;
}

int signExtension(int i) {
    int value = (0x0000FFFF & i);
    int mask = 0x00008000;
    if (mask & i) {
        value += 0xFFFF0000;
    }
    return value;
}

void execute(instrFormat instr){
    reg[0] = 0;
    switch(instr.opCode) {
        case 0x00:
            switch (instr.funct){
                case add: //cout << "add" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = ADD(reg[instr.rs], reg[instr.rt]);
                    break;
                case addu: //cout << "addu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt << '\n';
                    EX_MEM[1].exOutput = ADDU(reg[instr.rs], reg[instr.rt]);
                    break;
                case and_f: //cout << "and_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = AND_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case nor: //cout << "nor" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = NOR(reg[instr.rs], reg[instr.rt]);
                    break;
                case or_f: //cout << "or_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = OR_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case movn: //cout << "movn" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = reg[instr.rs];
                    break;
                case movz: //cout << "movz" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = reg[instr.rs];
                    break;
                case slt: //cout << "slt" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = SLT(reg[instr.rs], reg[instr.rt]);
                    break;
                case sltu: //cout << "sltu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = SLTU(reg[instr.rs], reg[instr.rt]);
                    break;
                case sll: //cout << "sll" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.shamt <<  '\n';
                    EX_MEM[1].exOutput = SLL(reg[instr.rt], instr.shamt);
                    break;
                case srl: //cout << "srl" <<", " << instr.rd << ", " <<  instr.rs << ", " << instr.shamt <<  '\n';
                    EX_MEM[1].exOutput = SRL(reg[instr.rt], instr.shamt);
                    break;
                case sub: //cout << "sub" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = SUB(reg[instr.rs], reg[instr.rt]);
                    break;
                case subu: //cout << "subu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = SUBU(reg[instr.rs], reg[instr.rt]);
                    break;
                case xor_f: //cout << "xor_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    EX_MEM[1].exOutput = XOR_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case jr:
                    //cout << "jr" << " " << reg[instr.rs] << '\n';
                    break;
            }
            break;
        case addi: //cout << "addi" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            EX_MEM[1].exOutput = ADDI(reg[instr.rs], instr.imm);
            break;
        case addiu: //cout << "addiu" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            EX_MEM[1].exOutput = ADDIU(reg[instr.rs], instr.imm);
            break;
        case andi: //cout << "andi" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            EX_MEM[1].exOutput = ANDI(reg[instr.rs], instr.imm);
            break;
        case xori: //cout << "xori" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            EX_MEM[1].exOutput = XORI(reg[instr.rs], instr.imm);
            break;
        case ori: //cout << "ori" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            EX_MEM[1].exOutput = ORI(instr.rs, instr.imm);
            break;
        case slti: //cout << "stli" <<  ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            EX_MEM[1].exOutput = SLTI(reg[instr.rs], instr.imm);
            break;
        case sltiu: //cout << "sltiu" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            EX_MEM[1].exOutput =  SLTIU(reg[instr.rs], instr.imm);
            break;
        case sb: //cout << "sb" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            EX_MEM[1].exOutput = (reg[instr.rs] + instr.imm) / 4;
            EX_MEM[1].pos = (instr.imm + reg[instr.rs]) % 4;
            break;
        case sh: //cout << "sh" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            EX_MEM[1].exOutput = (reg[instr.rs] + instr.imm) / 4;
            EX_MEM[1].pos = (instr.imm + reg[instr.rs]) % 2;
            break;
        case sw: //cout << "sw" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            EX_MEM[1].exOutput = (reg[instr.rs] + instr.imm) / 4;
            break;
        case lb: //cout << "lb" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            EX_MEM[1].exOutput = (reg[instr.rs] + instr.imm) / 4;
            EX_MEM[1].pos = (instr.imm + reg[instr.rs]) % 4;
            break;
        case lbu: //cout << "lbu" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            EX_MEM[1].exOutput = (reg[instr.rs] + instr.imm) / 4;
            EX_MEM[1].pos = (instr.imm + reg[instr.rs]) % 4;
            break;
        case lhu: //cout << "lhu" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            EX_MEM[1].exOutput = (reg[instr.rs] + instr.imm) / 4;
            EX_MEM[1].pos = (instr.imm + reg[instr.rs]) % 2;
            break;
        case lw: //cout << "lw" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            EX_MEM[1].exOutput = (reg[instr.rs] + instr.imm) / 4;
            break;
        case lui: //cout << "lui" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            EX_MEM[1].exOutput = signExtension(instr.imm | 0xFFFF);
            break;
        case seb: //cout << "seb" << '\n';
            EX_MEM[1].exOutput = signExtension(reg[instr.rt]);
            break;
        case beq: //cout << "beq" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case bne: //cout << "bne" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case bgtz:// cout << "bgtz" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case bltz: //cout << "bltz" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case blez: //cout << "blez" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case j: //cout << "j" << instr.address << '\n';
            break;
        case jal: //cout << "jal " << instr.address << '\n';
            break;
    }

    return;
}