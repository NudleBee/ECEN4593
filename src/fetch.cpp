//
// Created by Nathan Pottorff on 4/24/17.
//Finds the next instruction from instruction memory. Converts into opcode,

#include "fetch.h"
#include "initalization.h"


using namespace std;

void fetch(int inst){
    //cout << "FETCH: " << inst << '\n';
    IF_ID[1] = inst;
    return;
}