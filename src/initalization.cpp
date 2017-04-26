//
// Created by Nathan Pottorff on 4/25/17.
//

#include<iostream>
#include<fstream>
#include<cstdint>
#include "initalization.h"


using namespace std;

int readFile(string fileName){
    //Read in program files, and initialize the instruction memory (instMem)
    string wrd, tmp;
    uint32_t *instMem;
    int c = 0;
    ifstream program;
    program.open (fileName);
    if (program.is_open()) {
        while (getline(program, tmp)) {
            c = c + 1;
        }
    }
    else cout << "Couldn't open file" << '\n';

    instMem = new uint32_t [c];
    program.close();

    program.open (fileName);
    if(program.is_open()) {
        int i = 0;
        while (getline(program, wrd, ',')) {
            getline(program, tmp);
            instMem[i] = stoul(wrd, nullptr, 16);
            cout << i << " " << wrd << " " << instMem[i] << '\n';
            i++;
        }
    }
    else cout << "Couldn't open file" << '\n';

    return c;
}