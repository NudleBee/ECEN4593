#include <iostream>
#include "src/initalization.cpp"
#include "src/fetch.cpp"
#include "src/decode.cpp"

using namespace std;

int instMem[500];
//int mainMemory[1200] = {0};
int sp, fp, pc;
int clk, CPI, *Ihit, Dhit;

int shadowReg[2];
int shadowReg2[2];
int shadowReg3[2];
int shadowReg4[2];


int main() {

    int counter = readFile("../src/Program2File1.txt", instMem);

    reg[29] = instMem[0];
    reg[30] = instMem[1];
    pc = instMem[5];

    //shove instruction through a loop
    for(int instI = pc; instI != 0; instI++) {
        //cout << instMem[instI] << '\n';
        fetch(instI, instMem);
        //cout << Instruction[instI].opCode << ' ' <<  Instruction[instI].rType << '\n';
        int branch = decode(Instruction[instI], instI, mainMemory);

        /*cout << "===========Registers[" << instI << "]===========" << '\n';
        for (int k = 0; k <= 31; k++) {
            cout << "reg[" << k << "] " << reg[k] << '\n';
        }*/

        // Add word branch to word instI (then instI++)
        instI = branch;

        if(instI == 0){
            return 0;
        }
    }
    //printMem();


    return 0;
}