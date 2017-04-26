//
// Created by Nathan Pottorff on 4/24/17.
//
#include <cstdint>

#ifndef ECEN4593_DECODE_H
#define ECEN4593_DECODE_H


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



#endif //ECEN4593_DECODE_H
