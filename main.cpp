#include <iostream>
#include "src/initalization.cpp"
#include "src/fetch.cpp"

using namespace std;

uint32_t instMem[500];
int sp, fp, pc;
int reg[32];
int clk, CPI, *Ihit, Dhit;

int main() {

    int counter = readFile("../src/Program1File1.txt", instMem);

    sp = instMem[0];
    fp = instMem[1];
    pc = instMem[5];

    //shove instruction through a loop
    for(int instI = 10; instI <= counter; instI++){
        //cout << instMem[instI] << '\n';
        fetch(instI, instMem);
        //cout << Instruction[instI].opCode << ' ' <<  Instruction[instI].rType << '\n';



    }



    return 0;
}