//
// Created by Nathan Pottorff on 4/24/17.
//

#ifndef ECEN4593_DECODE_H
#define ECEN4593_DECODE_H

// i or j types
#define andi 0xc
#define addi 0x8
#define addui 0x9
#define ori 0xd
#define xori 0xe
#define slti 0xa
#define sltiu 0xb
#define beq 0x4
#define blez 0x6
#define bltz 0x1
#define bne 0x5
#define bgtz 0x7
#define j 0x2
#define jal 0x3
#define lb 0x20
#define lbu 0x24
#define lhu 0x25
#define lui 0xf
#define lw 0x31
#define sb 0x28
#define sh 0x29
#define sw 0x2b


#define seb 0x1F //
#define jr 0x8 //special opCode, rs, 16bitd of 0, 8




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


int decode(instFormat instr);


#endif //ECEN4593_DECODE_H
