//
// Created by Nathan Pottorff on 4/25/17.
//

#include<iostream>
#include<fstream>
#include "initalization.h"


using namespace std;

extern string *instMem;

int readFile(string fileName){
    //Read in program files, and initialize the instruction memory (instMem)
    string wrd, tmp;
    string *instMem;
    int c = 0;
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
            cout << i << " " << instMem[i] << '\n';
            i++;
        }
    }
    else cout << "Couldn't open file" << '\n';

    return c;
}