//
// Created by Nathan Pottorff on 4/25/17.
//

#include<iostream>
#include<fstream>
#include "cache.h"
#include "initalization.h"


using namespace std;

cache iCache = newCache(I_CACHE_SIZE, BLOCK_SIZE);
cache dCache = newCache(D_CACHE_SIZE, BLOCK_SIZE);

int readFile(string fileName){
    //Read in program files, and initialize the instruction memory (instMem)
    string wrd, tmp;
    ifstream program;
    int i = 0;
    program.open (fileName);
    if(program.is_open()) {
        while (getline(program, wrd, ',')) {
            getline(program, tmp);
            mainMemory[i] = stoul(wrd, nullptr, 16);
            i++;
        }
    }
    else cout << "Couldn't open file" << '\n';

    return i;
}

void printMem(){
    cout << "========Main Memory==========" << '\n';
    for(int k = 0; k <= 1200; k++){
        cout << "mainMemory[" << k << "] " << mainMemory[k] << '\n';
    }
    return;
}

void shadowShift(){
    MEM_WB[2] = EX_MEM[1];
    EX_MEM[2] = ID_EX[1];

    if(stall == true){
        for (int i = 0; i < 3; i++) {
            EX_MEM[i] = EX_MEM[i + 1];
            MEM_WB[i] = MEM_WB[i + 1];
        }
        stall = false;
    }
    else {
        for (int i = 0; i < 3; i++) {
            IF_ID[i] = IF_ID[i + 1];
            ID_EX[i] = ID_EX[i + 1];
            EX_MEM[i] = EX_MEM[i + 1];
            MEM_WB[i] = MEM_WB[i + 1];
        }
    }
    return;
}