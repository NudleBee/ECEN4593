//
// Created by Nathan Pottorff on 4/24/17.
//Finds the next instruction from instruction memory. Converts into opcode,

#include "fetch.h"

#include <iostream>
#include <fstream>


using namespace std;

void fetch(int *i){
    int op = (instMem[i] >> opCode_SHIFT) & opCode_MASK;
    cout << op << '\n';
    return;
}