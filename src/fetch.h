//
// Created by Nathan Pottorff on 4/24/17.
//

#ifndef ECEN4593_FETCH_H
#define ECEN4593_FETCH_H

#include <iostream>

using namespace std;

struct instFormat {
    int opCode;
    int rs;
    int rt;
    int rd;
    int shamt;
    int funct;
    int imm;
    int address;
    bool rType;

};

#define r_type 0x00

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

void assignRType();

void assignIType();

void fetch(int i, int *inst);

#endif //ECEN4593_FETCH_H
