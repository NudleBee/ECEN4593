//
// Created by Nathan Pottorff on 4/25/17.
//

#include<iostream>
#include<fstream>
#include "initalization.h"


using namespace std;

int readFile(string fileName, uint32_t *inst){
    //Read in program files, and initialize the instruction memory (instMem)
    string wrd, tmp;
    ifstream program;
    int i = 0;
    program.open (fileName);
    if(program.is_open()) {
        while (getline(program, wrd, ',')) {
            getline(program, tmp);
            inst[i] = stoul(wrd, nullptr, 16);
            //cout << i << " " << wrd << " " << inst[i] << '\n';
            i++;
        }
    }
    else cout << "Couldn't open file" << '\n';

    return i;
}