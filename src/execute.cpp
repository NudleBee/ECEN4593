//
// Created by Nathan Pottorff on 4/24/17.
//

#include "execute.h"


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

int LB(){

}

int LBU(){

}

int LHU(){

}

int LUI(){

}

int LW(){

}

int ORI(){

}

int SLTI(){

}

int SLTIU(){

}

int SB(){

}

int SH(){

}

int SW(){

}

int SEB(){

}