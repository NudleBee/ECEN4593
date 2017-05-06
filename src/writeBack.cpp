//
// Created by Nathan Pottorff on 4/24/17.
//

#include "writeBack.h"
#include "initalization.h"

void writeBack(instrFormat instr){
    cout << "WriteBack: ";
    reg[0] = 0;
    switch(instr.opCode) {
        case 0x00:
            switch (instr.funct){
                case add: cout << "add" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case addu: cout << "addu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt << '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case and_f: cout << "and_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case nor: cout << "nor" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case or_f: cout << "or_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case slt: cout << "slt" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case sltu: cout << "sltu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case sll: cout << "sll" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.shamt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case srl: cout << "srl" <<", " << instr.rd << ", " <<  instr.rs << ", " << instr.shamt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case sub: cout << "sub" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case subu: cout << "subu" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case xor_f: cout << "xor_f" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    reg[instr.rd] = instr.exOutput;
                    break;
                case jr:
                    cout << "jr" << " " << reg[instr.rs] << '\n';

                case movn:
                    cout << "movn" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    if(reg[instr.rt] != 0){
                        reg[instr.rd] = instr.exOutput;
                    }
                    break;
                case movz:
                    cout << "movz" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.rt <<  '\n';
                    if(reg[instr.rt] == 0){
                        reg[instr.rd] = instr.exOutput;
                    }
                    break;
            }
            break;
        case addi: cout << "addi" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = instr.exOutput;
            break;
        case addiu: cout << "addiu" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = instr.exOutput;
            break;
        case andi: cout << "andi" << ", " << instr.rd << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = instr.exOutput;
            break;
        case xori: cout << "xori" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = instr.exOutput;
            break;
        case ori: cout << "ori" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = instr.exOutput;
            break;
        case slti: cout << "stli" <<  ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = instr.exOutput;
            break;
        case sltiu: cout << "sltiu" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = instr.exOutput;
            break;
        case sb: cout << "sb" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            mainMemory[instr.exOutput] = instr.rt;
            break;
        case sh: cout << "sh" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            mainMemory[instr.exOutput] = instr.rt;
            break;
        case sw: cout << "sw" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            mainMemory[instr.exOutput] = instr.rt;
            break;
        case lb: cout << "lb" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            reg[instr.rt] = instr.memOutput;
            break;
        case lbu: cout << "lbu" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            reg[instr.rt] = instr.memOutput;
            break;
        case lhu: cout << "lbh" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            reg[instr.rt] = instr.memOutput;
            break;
        case lui: cout << "lui" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            reg[instr.rt] = instr.exOutput;
            break;
        case lw: cout << "lw" << ", " << instr.rt << ", " <<  instr.imm << "(" << instr.rs <<  ")" << '\n';
            reg[instr.rt] = instr.memOutput;
            break;
        case seb:
            reg[instr.rd] = instr.exOutput;
            break;
        case beq: cout << "beq" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case bne: cout << "bne" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case bgtz: cout << "bgtz" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case bltz: cout << "bltz" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case blez: cout << "blez" << ", " << instr.rt << ", " <<  instr.rs << ", " << instr.imm <<  '\n';
            break;
        case j: cout << "j" << instr.address << '\n';
            break;
        case jal: cout << "jal " << instr.address << '\n';
            break;
    }
    return;
}