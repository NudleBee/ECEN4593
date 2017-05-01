//
// Created by Nathan Pottorff on 4/24/17.
//

#ifndef ECEN4593_DECODE_H
#define ECEN4593_DECODE_H

// i or j types
#define andi 0xc //0 extended (no change)
#define addi 0x8 //sign extended
#define addui 0x9 //sign extended
#define ori 0xd //0 extended
#define xori 0xe //sign extended
#define slti 0xa //sign extended
#define sltiu 0xb //sign extended
#define beq 0x4
#define blez 0x6
#define bltz 0x1
#define bne 0x5
#define bgtz 0x7
#define j 0x2
#define jal 0x3
#define lb 0x20
#define lbu 0x24 //sign extended
#define lhu 0x25 //sign extended
#define lui 0xf // load lower halfword imm to upper halfword register
#define lw 0x31 //sign extended
#define sb 0x28 //sign extended
#define sh 0x29 //sign extended
#define sw 0x2b //sign extended


#define seb 0x1F //
#define jr 0x8 //special opCode, rs, 16bit of 0, 8

// r types
#define add 0x20
#define addu 0x21
#define and_f 0x24
#define nor 0x27
#define or_f 0x25
#define movn 0xb
#define movz 0xa
#define slt 0x2a
#define sltu 0x2b
#define sll 0x00
#define srl 0x2
#define sub 0x22
#define subu 0x23
#define xor_f 0x26

//Load store shifts
#define byte0 0xFFFFFF00
#define byte1 0xFFFF00FF
#define byte2 0xFF00FFFF
#define byte3 0x00FFFFFF

#define hwrd0 0xFFFF0000
#define hwrd1 0x0000FFFF

#define shift8 8
#define shift16 16
#define shift24 24
#define shift28 28

int decode(instFormat instr, int programCounter);


#endif //ECEN4593_DECODE_H
