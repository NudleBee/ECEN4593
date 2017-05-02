//
// Created by Nathan Pottorff on 4/24/17.
//

#include "decode.h"
#include "fetch.h"
#include "execute.cpp"
#include "writeBack.cpp"

using namespace std;

//Branch Detection (update pc)

int decode(instFormat instr, int programCounter, int *mainMemory){
    switch(instr.opCode) {
        case 0x00:
            switch (instr.funct){
                case add: cout << "add" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = ADD(reg[instr.rs], reg[instr.rt]);
                    break;
                case addu: cout << "addu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt << '\n';
                    reg[instr.rd] = ADDU(reg[instr.rs], reg[instr.rt]);
                    break;
                case and_f: cout << "and_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = AND_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case nor: cout << "nor" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = NOR(reg[instr.rs], reg[instr.rt]);
                    break;
                case or_f: cout << "or_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = OR_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case movn: cout << "movn" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    if(reg[instr.rt] != 0){
                        reg[instr.rd] = reg[instr.rs];
                    }
                    break;
                case movz: cout << "movz" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    if(reg[instr.rt] == 0){
                        reg[instr.rd] = reg[instr.rs];
                    }
                    break;
                case slt: cout << "slt" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = SLT(reg[instr.rs], reg[instr.rt]);
                    break;
                case sltu: cout << "sltu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = SLTU(reg[instr.rs], reg[instr.rt]);
                    break;
                case sll: cout << "sll" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.shamt <<  '\n';
                    reg[instr.rd] = SLL(reg[instr.rt], instr.shamt);
                    break;
                case srl: cout << "srl" <<", " << instr.rd << ", " <<  instr.rs << ", " << instr.shamt <<  '\n';
                    reg[instr.rd] = SRL(reg[instr.rt], instr.shamt);
                    break;
                case sub: cout << "sub" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = SUB(reg[instr.rs], reg[instr.rt]);
                    break;
                case subu: cout << "subu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = SUBU(reg[instr.rs], reg[instr.rt]);
                    break;
                case xor_f: cout << "xor_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = XOR_F(reg[instr.rs], reg[instr.rt]);
                    break;
                case jr: cout << "jr";
                    cout << " " << reg[instr.rs] << '\n';
                    return reg[instr.rs] - 1;

            }
            break;
        case addi: cout << "addi" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = ADDI(reg[instr.rs], instr.imm);
            break;
        case addui: cout << "addui" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = ADDUI(reg[instr.rs], instr.imm);
            break;
        case andi: cout << "andi" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = ANDI(reg[instr.rs], instr.imm);
            break;
        case xori: cout << "xori" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = XORI(reg[instr.rs], instr.imm);
            break;
        case beq: cout << "beq" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            if(BEQ(reg[instr.rs], reg[instr.rt])){
                return programCounter + instr.imm;
            }
            break;
        case bne: cout << "bne" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            if(BNE(reg[instr.rs], reg[instr.rt])){
                return programCounter + instr.imm;
            }
            break;
        case bgtz: cout << "bgtz" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            if(BGTZ(reg[instr.rs])){
                return programCounter + instr.imm;
            }
            break;
        case bltz: cout << "bltz" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            if(BLTZ(reg[instr.rs])){
                return programCounter + instr.imm;
            }
            break;
        case blez: cout << "blez" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            if(BLEZ(reg[instr.rs])){
                return programCounter + instr.imm;
            }
            break;
        case j: cout << "j" << '\n';
            return instr.address - 1;
        case jal: cout << "jal " << instr.address << '\n';
            reg[31] = programCounter + 2;
            return instr.address - 1;
        case lb: cout << "lb" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            LB(instr.rt, instr.rs, instr.imm);
            break;
        case lbu: cout << "lbu" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            LBU(instr.rt, instr.rs, instr.imm);
            break;
        case lhu: cout << "lhu" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            LHU(instr.rt, instr.rs, instr.imm);
            break;
        case lui: cout << "lui" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = signExtension(instr.imm | 0xFFFF);
            break;
        case lw: cout << "lw" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            reg[instr.rt] = mainMemory[(reg[instr.rs] + instr.imm) / 4];
            //printMem();
            break;
        case ori: cout << "ori" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = ORI(instr.rs, instr.imm);
            break;
        case slti: cout << "stli" <<  ", " << instr.rd << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = SLTI(reg[instr.rs], instr.imm);
            break;
        case sltiu: cout << "sltiu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] =  SLTIU(reg[instr.rs], instr.imm);
            break;
        case sb: cout << "sb" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            SB(instr.rt, instr.rs, instr.imm);
            break;
        case sh: cout << "sh" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            SH(instr.rt, instr.rs, instr.imm);
            break;
        case sw: cout << "sw" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            mainMemory[(reg[instr.rs] + instr.imm) / 4] = reg[instr.rt];
            //printMem();
            break;
        case seb: cout << "seb" << '\n';
            reg[instr.rd] = signExtension(reg[instr.rt]);
            break;
    }


    return programCounter;
}