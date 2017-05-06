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
    reg[0] = 0;
    instrFormat nullFormat;
    ID_EX[1].opCode = (instr >> opCode_SHIFT) & opCode_MASK;
    if (ID_EX[1].opCode == r_type){
        ID_EX[1].rs = (instr >> rs_SHIFT) & rs_MASK;
        ID_EX[1].rt = (instr >> rt_SHIFT) & rt_MASK;
        ID_EX[1].rd = (instr >> rd_SHIFT) & rd_MASK;
        ID_EX[1].shamt = (instr >> shamt_SHIFT) & shamt_MASK;
        ID_EX[1].funct = instr & funct_MASK;
        ID_EX[1].imm = 0;
        ID_EX[1].address = 0;
        //cout << "DECODE: " << ID_EX[1].funct;
    }
    else {
        ID_EX[1].rs = (instr >> rs_SHIFT) & rs_MASK;
        ID_EX[1].rt = (instr >> rt_SHIFT) & rt_MASK;
        ID_EX[1].imm = instr & imm_MASK;
        ID_EX[1].address = instr & add_MASK;
        //cout << "DECODE: " << ID_EX[1].opCode;
    }

    int s = ID_EX[1].imm & 0x8000;

    if(s == 0x8000) {
        ID_EX[1].imm = (int16_t) ID_EX[1].imm;
    }

    //stall
    if (((IF_ID[1] >> opCode_SHIFT) & opCode_MASK) != sw) {
        if (((IF_ID[1] >> opCode_SHIFT) & opCode_MASK) != sh) {
            if (((IF_ID[1] >> opCode_SHIFT) & opCode_MASK) != sb) {
                switch (ID_EX[1].opCode) {
                    case lw:
                        if (ID_EX[1].rt == ((IF_ID[1] >> rs_SHIFT) & rs_MASK)) {
                            stall = true;
                        } else if (ID_EX[1].rt == ((IF_ID[1] >> rt_SHIFT) & rt_MASK)) {
                            stall = true;
                        }
                        break;
                    case lb:
                        if (ID_EX[1].rt == ((IF_ID[1] >> rs_SHIFT) & rs_MASK)) {
                            stall = true;
                        } else if (ID_EX[1].rt == ((IF_ID[1] >> rt_SHIFT) & rt_MASK)) {
                            stall = true;
                        }
                        break;
                    case lbu:
                        if (ID_EX[1].rt == ((IF_ID[1] >> rs_SHIFT) & rs_MASK)) {
                            stall = true;
                        } else if (ID_EX[1].rt == ((IF_ID[1] >> rt_SHIFT) & rt_MASK)) {
                            stall = true;
                        }
                        break;
                    case lhu:
                        if (ID_EX[1].rt == ((IF_ID[1] >> rs_SHIFT) & rs_MASK)) {
                            stall = true;
                        } else if (ID_EX[1].rt == ((IF_ID[1] >> rt_SHIFT) & rt_MASK)) {
                            stall = true;
                        }
                        break;
                }
            }
        }
    }





    //Branches, jumps, fowarding
    switch(ID_EX[1].opCode){
        case beq:
            if(BEQ(reg[ID_EX[1].rs], reg[ID_EX[1].rt])){
                return programCounter + ID_EX[1].imm - 1;
            }
            break;
        case bne:
            if(BNE(reg[ID_EX[1].rs], reg[ID_EX[1].rt])){
                return programCounter + ID_EX[1].imm - 1;
            }
            break;
        case bgtz:
            if(BGTZ(reg[ID_EX[1].rs])){
                ID_EX[1].rt = 0x01;
                return programCounter + ID_EX[1].imm - 1;
            }
            break;
        case bltz:
            if(BLTZ(reg[ID_EX[1].rs])){
                ID_EX[1].rt = 0x01;
                return programCounter + ID_EX[1].imm - 1;
            }
            break;
        case blez:
            if(BLEZ(reg[ID_EX[1].rs])){
                ID_EX[1].rt = 0x01;
                return programCounter + ID_EX[1].imm - 1;
            }
            break;
        case j:
            return ID_EX[1].address - 1;
        case jal:
            reg[31] = programCounter + 2;
            return ID_EX[1].address - 1;
        case 0x00:
            switch(ID_EX[1].funct) {
                case jr:
                    return reg[ID_EX[1].rs] - 1;
            }
    }

    //cout << " " << ID_EX[1].rd << ", " << ID_EX[1].rs << ", " << ID_EX[1].rt << '\n';
    return programCounter;
}