//
// Created by Nathan Pottorff on 4/24/17.
//

#ifndef ECEN4593_DECODE_H
#define ECEN4593_DECODE_H

#define opCode_MASK 0x0000003F
#define rs_MASK 0x0000001F
#define rt_MASK 0x0000001F
#define rd_MASK 0x0000001F
#define shamt_MASK 0x0000003F
#define funct_MASK 0x0000003F
#define imm_MASK 0x0000FFFF
#define add_MASK 0x03FFFFFF

#define opCode_SHIFT 26
#define rs_SHIFT 21
#define rt_SHIFT 16
#define rd_SHIFT 11
#define shamt_SHIFT 6

#define jr 0x8 //special opCode, rs, 16bit of 0, 8
#define beq 0x4
#define blez 0x6
#define bltz 0x1
#define bne 0x5
#define bgtz 0x7
#define j 0x2
#define jal 0x3

int decode(int instr, int programCounter);


#endif //ECEN4593_DECODE_H
