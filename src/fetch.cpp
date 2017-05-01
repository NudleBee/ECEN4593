//
// Created by Nathan Pottorff on 4/24/17.
//Finds the next instruction from instruction memory. Converts into opcode,

#include "fetch.h"
#include <iostream>
#include <fstream>

instFormat Instruction[500];

using namespace std;

void fetch(int i, int *inst){
    Instruction[i].opCode = (inst[i] >> opCode_SHIFT) & opCode_MASK;
    if (Instruction[i].opCode == r_type){
        Instruction[i].rType = true;
        Instruction[i].rs = (inst[i] >> rs_SHIFT) & rs_MASK;
        Instruction[i].rt = (inst[i] >> rt_SHIFT) & rt_MASK;
        Instruction[i].rd = (inst[i] >> rd_SHIFT) & rd_MASK;
        Instruction[i].shamt = (inst[i] >> shamt_SHIFT) & shamt_MASK;
        Instruction[i].funct = inst[i] & funct_MASK;
        Instruction[i].imm = 0;
        Instruction[i].address = 0;
    }
    else {
        Instruction[i].rType = false;
        Instruction[i].rs = (inst[i] >> rs_SHIFT) & rs_MASK;
        Instruction[i].rt = (inst[i] >> rt_SHIFT) & rt_MASK;
        Instruction[i].imm = inst[i] & imm_MASK;
        Instruction[i].address = inst[i] & add_MASK;
    }

    int s = Instruction[i].imm & 0x8000;

    if(s == 0x8000) {
        cout << Instruction[i].imm << " is now ";
        Instruction[i].imm = (int16_t) Instruction[i].imm;
        cout << Instruction[i].imm << '\n';
    }


    //Forwarding check

    return;
}