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

int LB(int rt, int rs, int imm);

int LBU(int rt, int rs, uint32_t imm);

int LHU(int rt, int rs, uint32_t imm);

int ORI(int rs, int imm);

int SLTI(int rs, int imm);

int SLTIU(int rs, uint32_t);

int SB(int rt, int rs, int imm);

int SH(int rt, int rs, int imm);

//r types
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

int signExtension(int i);

#endif //ECEN4593_EXECUTE_H
