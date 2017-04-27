//
// Created by Nathan Pottorff on 4/24/17.
//

#ifndef ECEN4593_EXECUTE_H
#define ECEN4593_EXECUTE_H

//i types
int ADDI(int rs, int imm);

int ADDUI(int rs, uint32_t imm);

int ANDI(int rs, int imm);

int XORI(int rs, int imm);

bool BEQ(int rs, int rt);

bool BNE(int rs, int rt);

bool BGTZ(int rs);

bool BLTZ(int rs);

bool BLEZ(int rs);

int LB();
int LBU();
int LHU();
int LUI();
int LW();
int ORI();
int SLTI();
int SLTIU();
int SB();
int SH();
int SW();

//r types
int NOP();

int ADD(int rs, int rt);

int ADDU(uint32_t rs, uint32_t rt);

int AND_F(int rs, int rt);

int NOR(int rs, int rt);

int OR_F(int rs, int rt);

int SLT(int rs, int rt);

int SLTU(uint32_t rs, uint32_t rt);

int SLL(int rt, int shamt);

int SRL(int rt, int shamt);

int SUB(int rs, int rt);

int SUBU(uint32_t rs, uint32_t rt);

int XOR_F(int rs, int rt);



//Weird types
int SEB();

#endif //ECEN4593_EXECUTE_H
