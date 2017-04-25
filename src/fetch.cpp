//
// Created by Nathan Pottorff on 4/24/17.
//Finds the next instruction from instruction memory. Converts into opcode,

#include "fetch.h"

#include <iostream>
#include <fstream>


using namespace std;

string *instMem;

string fetch(int pc){
    string comd;
    instMem[pc];

    return comd;
}

int readFile(string fileName){
    //Read in program files, and initialize the instruction memory (instMem)
    string wrd, tmp;
    int c;
    ifstream program;
    program.open (fileName);
    if (program.is_open()) {
        while (getline(program, tmp)) {
            c = c + 1;
        }
    }
    else cout << "Couldn't open file" << '\n';

    instMem = new string [c];
    program.close();

    program.open (fileName);
    if(program.is_open()) {
        int i = 0;
        while (getline(program, wrd, ',')) {
            getline(program, tmp);
            instMem[i] = wrd;
            //cout << i << " " << instMem[i] << '\n';
            i++;
        }
    }
    else cout << "Couldn't open file" << '\n';

    return c;
}