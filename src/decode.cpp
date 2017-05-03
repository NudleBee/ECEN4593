//
// Created by Nathan Pottorff on 4/24/17.
//

#include "decode.h"
#include "initalization.h"

using namespace std;

//Branch Detection (update pc)

bool BEQ(int rs, int rt){
    if (rs == rt){
        return true;
    }
    return false;
}

bool BNE(int rs, int rt){
    if (rs != rt){
        return true;
    }
    return false;
}

bool BGTZ(int rs){
    if (rs > 0){
        return true;
    }
    return false;
}

bool BLTZ(int rs){
    if (rs < 0){
        return true;
    }
    return false;
}

bool BLEZ(int rs){
    if (rs <= 0){
        return true;
    }
    return false;
}

int decode(int instr, int programCounter){
    ID_EX[4].opCode = (instr >> opCode_SHIFT) & opCode_MASK;
    if (ID_EX[4].opCode == r_type){
        ID_EX[4].rs = (instr >> rs_SHIFT) & rs_MASK;
        ID_EX[4].rt = (instr >> rt_SHIFT) & rt_MASK;
        ID_EX[4].rd = (instr >> rd_SHIFT) & rd_MASK;
        ID_EX[4].shamt = (instr >> shamt_SHIFT) & shamt_MASK;
        ID_EX[4].funct = instr & funct_MASK;
        ID_EX[4].imm = 0;
        ID_EX[4].address = 0;
    }
    else {
        ID_EX[4].rs = (instr >> rs_SHIFT) & rs_MASK;
        ID_EX[4].rt = (instr >> rt_SHIFT) & rt_MASK;
        ID_EX[4].imm = instr & imm_MASK;
        ID_EX[4].address = instr & add_MASK;
    }

    int s = ID_EX[4].imm & 0x8000;

    if(s == 0x8000) {
        //cout << Instruction[i].imm << " is now ";
        ID_EX[4].imm = (int16_t) ID_EX[4].imm;
        //cout << Instruction[i].imm << '\n';
    }
    //Branches and jumps
    switch(ID_EX[4].opCode){
        case beq: cout << "beq" << ", " << ID_EX[4].rt << ", " <<  ID_EX[4].rs << ", " << ID_EX[4].imm <<  '\n';
            if(BEQ(reg[ID_EX[4].rs], reg[ID_EX[4].rt])){
                return programCounter + ID_EX[4].imm;
            }
            break;
        case bne: cout << "bne" << ", " << ID_EX[4].rt << ", " <<  ID_EX[4].rs << ", " << ID_EX[4].imm <<  '\n';
            if(BNE(reg[ID_EX[4].rs], reg[ID_EX[4].rt])){
                return programCounter + ID_EX[4].imm;
            }
            break;
        case bgtz: cout << "bgtz" << ", " << ID_EX[4].rt << ", " <<  ID_EX[4].rs << ", " << ID_EX[4].imm <<  '\n';
            if(BGTZ(reg[ID_EX[4].rs])){
                return programCounter + ID_EX[4].imm;
            }
            break;
        case bltz: cout << "bltz" << ", " << ID_EX[4].rt << ", " <<  ID_EX[4].rs << ", " << ID_EX[4].imm <<  '\n';
            if(BLTZ(reg[ID_EX[4].rs])){
                return programCounter + ID_EX[4].imm;
            }
            break;
        case blez: cout << "blez" << ", " << ID_EX[4].rt << ", " <<  ID_EX[4].rs << ", " << ID_EX[4].imm <<  '\n';
            if(BLEZ(reg[ID_EX[4].rs])){
                return programCounter + ID_EX[4].imm;
            }
            break;
        case j: cout << "j" << '\n';
            return ID_EX[4].address - 1;
        case jal: cout << "jal " << ID_EX[4].address << '\n';
            reg[31] = programCounter + 2;
            return ID_EX[4].address - 1;
        case 0x00:
            switch(ID_EX[4].funct) {
                case jr:
                    cout << "jr";
                    cout << " " << reg[ID_EX[4].rs] << '\n';
                    return reg[ID_EX[4].rs] - 1;
            }
    }

    return programCounter;
}