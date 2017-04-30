//
// Created by Nathan Pottorff on 4/24/17.
//

#include "execute.h"

int reg[32] = {0};
int mainMemory[1200] = {0};

int ADD(int rs, int rt){
    return rs + rs;
}

int ADDU(uint32_t rs, uint32_t rt){
    return rs + rt;
}

int AND_F(int rs, int rt){
    return rs & rs;

}

int NOR(int rs, int rt){
    return ~(rs|rs);
}

int OR_F(int rs, int rt){
    return rs | rs;

}

int SLT(int rs, int rt){
    if(rs < rt){
        return 1;
    }
    return 0;

}

int SLTU(uint32_t rs, uint32_t rt){
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

int SUBU(uint32_t rs, uint32_t rt){
    return rs - rt;
}

int XOR_F(int rs, int rt){
    return rs^rt;
}

int ADDI(int rs, int imm){
    return rs + imm;
}

int ADDUI(int rs, uint32_t imm){
    return rs + imm;
}

int ANDI(int rs, int imm){
    return rs & imm;
}

int XORI(int rs, int imm){
    return rs^imm;
}

bool BEQ(int rs, int rt){
    if (rs == rt){
        return true;
    }
    else false;

}

bool BNE(int rs, int rt){
    if (rs != rt){
        return true;
    }
    else false;
}

bool BGTZ(int rs){
    if (rs > 0){
        return true;
    }
    else false;
}

bool BLTZ(int rs){
    if (rs < 0){
        return true;
    }
    else false;
}

bool BLEZ(int rs){
    if (rs <= 0){
        return true;
    }
    else false;
}

int LB(int rt, int rs, int imm){
    int index = (imm + reg[rs]) / 4;
    int pos = (imm + reg[rs]) % 4;
    switch(pos) {
        case 0:
            reg[rt] = (reg[rt] & byte0) & ((mainMemory[index] & byte0));
            break;
        case 1:
            reg[rt] = (reg[rt] & byte1) & ((mainMemory[index] & byte0) << shift8);
            break;
        case 2:
            reg[rt] = (reg[rt] & byte2) & ((mainMemory[index] & byte0) << shift16);
            break;
        case 3:
            reg[rt] = (reg[rt] & byte3) & ((mainMemory[index] & byte0) << shift24);
            break;
    }
}

int LBU(int rt, int rs, uint32_t imm){
    int index = (imm + reg[rs]) / 4;
    int pos = (imm + reg[rs]) % 4;
    switch(pos) {
        case 0:
            reg[rt] = (reg[rt] & byte0) & ((mainMemory[index] & byte0));
            break;
        case 1:
            reg[rt] = (reg[rt] & byte1) & ((mainMemory[index] & byte0) << shift8);
            break;
        case 2:
            reg[rt] = (reg[rt] & byte2) & ((mainMemory[index] & byte0) << shift16);
            break;
        case 3:
            reg[rt] = (reg[rt] & byte3) & ((mainMemory[index] & byte0) << shift24);
            break;
    }
}

int LHU(int rt, int rs, uint32_t imm){
    int index = (imm + reg[rs]) / 4;
    int pos = (imm + reg[rs]) % 2;
    switch(pos) {
        case 0:
            reg[rt] = (reg[rt] & hwrd0) & ((mainMemory[index] & hwrd0));
            break;
        case 1:
            reg[rt] = (reg[rt] & hwrd1) & ((mainMemory[index] & byte0) << shift16);
            break;
    }
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

int SLTIU(int rs, uint32_t imm){
    if(rs < imm){
        return 1;
    }
    return 0;
}

int SB(int rt, int rs, int imm){
    int index = (imm + reg[rs]) / 4;
    int pos = (imm + reg[rs]) % 4;
    switch(pos){
        case 0:
            mainMemory[index] = (mainMemory[index] & byte0) & (reg[rt] & byte0);
            break;
        case 1:
            mainMemory[index] = (mainMemory[index] & byte1) & ((reg[rt] & byte0) << shift8);
            break;
        case 2:
            mainMemory[index] = (mainMemory[index] & byte2) & ((reg[rt] & byte0) << shift16);
            break;
        case 3:
            mainMemory[index] = (mainMemory[index] & byte3) & ((reg[rt] & byte0) << shift24);
            break;
    }

}

int SH(int rt, int rs, int imm){
    int index = (imm + rs) / 4;
    int pos = (imm + rs) % 2;
    switch(pos) {
        case 0:
            mainMemory[index] = (mainMemory[index] & hwrd0) & (reg[rt] & hwrd0);
            break;
        case 1:
            mainMemory[index] = (mainMemory[index] & hwrd1) & ((reg[rt] & hwrd1) << shift16);
            break;
    }
}

int signExtension(int i) {
    int value = (0x0000FFFF & i);
    int mask = 0x00008000;
    if (mask & i) {
        value += 0xFFFF0000;
    }
    return value;
}