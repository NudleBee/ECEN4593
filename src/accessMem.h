//
// Created by Nathan Pottorff on 4/24/17.
//

#ifndef ECEN4593_ACCESSMEM_H
#define ECEN4593_ACCESSMEM_H

#define lb 0x20
#define lbu 0x24 //sign extended
#define lhu 0x25 //sign extended
#define lui 0xf // load lower halfword imm to upper halfword register
#define lw 0x23 //sign extended
#define sb 0x28 //sign extended
#define sh 0x29 //sign extended
#define sw 0x2b //sign extended

//Load store shifts
#define byte0 0xFFFFFF00
#define byte1 0xFFFF00FF
#define byte2 0xFF00FFFF
#define byte3 0x00FFFFFF

#define b0 0x000000FF
#define b1 0x0000FF00
#define b2 0x00FF0000
#define b3 0xFF000000

#define hwrd0 0xFFFF0000
#define hwrd1 0x0000FFFF

#define shift8 8
#define shift16 16
#define shift24 24
#define shift28 28

void accessMem(instrFormat instr, int i);

#endif //ECEN4593_ACCESSMEM_H
