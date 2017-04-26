//
// Created by Nathan Pottorff on 4/24/17.
//

#ifndef ECEN4593_FETCH_H
#define ECEN4593_FETCH_H

#include <iostream>

using namespace std;

struct rType {
    int opcode;
    int rs;
    int rt;
    int rd;
    int shamt;
    int funct;

};

struct iType {
    int opcode;
    int rs;
    int rt;
    uint16_t imm;
};

#define opCode_MASK 0xFC000000
#define rs_MASK 0x03E00000
#define rt_MASK 0x001F0000
#define rd_MASK 0x0000F800
#define shamt_MASK 0x000007C0
#define funct_MASK 0x0000003F

#define opCode_SHIFT 26
#define rs_SHIFT 21
#define rt_SHIFT 16
#define rd_SHIFT 11
#define shamt_SHIFT 6


void assignRType();

void assignIType();

void fetch(int *i);

#endif //ECEN4593_FETCH_H
