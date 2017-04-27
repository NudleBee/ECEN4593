#include <iostream>
#include "src/initalization.cpp"
#include "src/fetch.cpp"
#include "src/decode.cpp"

using namespace std;

uint32_t instMem[500];
int sp, fp, pc;
int clk, CPI, *Ihit, Dhit;

int main() {

    int counter = readFile("../src/Program1File1.txt", instMem);

    sp = instMem[0];
    fp = instMem[1];
    pc = instMem[5];

    //shove instruction through a loop
    for(int instI = 9; instI <= counter; instI++){
        //cout << instMem[instI] << '\n';
        fetch(instI, instMem);
        //cout << Instruction[instI].opCode << ' ' <<  Instruction[instI].rType << '\n';
        int branch = decode(Instruction[instI]);

        // Add word branch to word instI (then instI++)
        instI = instI + branch;

        cout << "===========Registers[" << instI<< "]===========" << '\n';
        for(int k = 0; k <= 31; k++){
            cout <<"reg[" << k << "] " << reg[k] << '\n';
        }

    }



    return 0;
}