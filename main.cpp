#include <iostream>
#include "src/initalization.cpp"
#include "src/fetch.cpp"
#include "src/decode.cpp"

using namespace std;

int instMem[500];
int sp, fp, pc;
int clk, CPI, *Ihit, Dhit;

int main() {

    int counter = readFile("../src/Program1File1.txt", instMem);

    reg[29] = instMem[0];
    reg[30] = instMem[1];
    pc = instMem[5];

    //shove instruction through a loop
    for(int instI = pc; instI != 0; instI++) {
        //cout << instMem[instI] << '\n';
        fetch(instI, instMem);
        //cout << Instruction[instI].opCode << ' ' <<  Instruction[instI].rType << '\n';
        int branch = decode(Instruction[instI], instI);

        cout << "===========Registers[" << instI << "]===========" << '\n';
        for (int k = 0; k <= 31; k++) {
            cout << "reg[" << k << "] " << reg[k] << '\n';
        }
        // Add word branch to word instI (then instI++)
        instI = branch;

    }


    return 0;
}