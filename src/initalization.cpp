//
// Created by Nathan Pottorff on 4/25/17.
//

#include<iostream>
#include<fstream>
#include "initalization.h"


using namespace std;

int readFile(string fileName){
    //Read in program files, and initialize the instruction memory (instMem)
    string wrd, tmp;
    ifstream program;
    int i = 0;
    program.open (fileName);
    if(program.is_open()) {
        while (getline(program, wrd, ',')) {
            getline(program, tmp);
            instrMem[i] = stoul(wrd, nullptr, 16);
            i++;
        }
    }
    else cout << "Couldn't open file" << '\n';

    return i;
}

void shadowShift(){
    MEM_WB[2] = EX_MEM[1];
    EX_MEM[2] = ID_EX[1];

    for (int i = 0; i < 3; i++) {
        IF_ID[i] = IF_ID[i + 1];
        ID_EX[i] = ID_EX[i + 1];
        EX_MEM[i] = EX_MEM[i + 1];
        MEM_WB[i] = MEM_WB[i + 1];
    }
    return;
}