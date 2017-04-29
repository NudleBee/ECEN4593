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
    int sEimm = signExtension(imm);
    return rs + sEimm;
}

int ADDUI(int rs, uint32_t imm){
    int sEimm = signExtension(imm);
    return rs + sEimm;
}

int ANDI(int rs, int imm){
    return rs & imm;
}

int XORI(int rs, int imm){
    int sEimm = signExtension(imm);
    return rs^sEimm;
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
    //int sEimm = signExtension(imm);


}

int LHU(){
    //int sEimm = signExtension(imm);


}

int LUI(){
   // int sEimm = signExtension(imm);


}

int LW(){
    //int sEimm = signExtension(imm);


}

int ORI(int rs, int imm){
    return rs | imm;


}

int SLTI(int rs, int imm){
    int sEimm = signExtension(imm);
    if(rs < sEimm){
        return 1;
    }
    return 0;

}

int SLTIU(int rs, uint32_t imm){
    int sEimm = signExtension(imm);
    if(rs < sEimm){
        return 1;
    }
    return 0;
}

int SB(){
    //int sEimm = signExtension(imm);


}

int SH(){
    //int sEimm = signExtension(imm);


}

int SW(){
    //int sEimm = signExtension(imm);


}

int SEB(){

}

int signExtension(int i) {
    int value = (0x0000FFFF & i);
    int mask = 0x00008000;
    if (mask & i) {
        value += 0xFFFF0000;
    }
    return value;
}