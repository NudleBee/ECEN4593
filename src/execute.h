//
// Created by Nathan Pottorff on 4/24/17.
//

#ifndef ECEN4593_EXECUTE_H
#define ECEN4593_EXECUTE_H

// i or j types
#define andi 0xc //0 extended (no change)
#define addi 0x8 //sign extended
#define addiu 0x9 //sign extended
#define ori 0xd //0 extended
#define xori 0xe //sign extended
#define slti 0xa //sign extended
#define sltiu 0xb //sign extended


#define seb 0x1F //

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

#define lb 0x20
#define lbu 0x24 //sign extended
#define lhu 0x25 //sign extended
#define lui 0xf // load lower halfword imm to upper halfword register
#define lw 0x23 //sign extended
#define sb 0x28 //sign extended
#define sh 0x29 //sign extended
#define sw 0x2b //sign extended

void execute(instrFormat instr);

#endif //ECEN4593_EXECUTE_H
