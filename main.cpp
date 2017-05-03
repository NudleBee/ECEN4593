#include <iostream>
#include "src/initalization.cpp"
#include "src/fetch.cpp"
#include "src/decode.cpp"
#include "src/execute.cpp"
#include "src/accessMem.cpp"
#include "src/writeBack.cpp"

using namespace std;

int main() {

    int counter = readFile("../src/Program1File1.txt");

    reg[29] = instrMem[0];
    reg[30] = instrMem[1];
    pc = instrMem[5];

    //shove instruction through a loop
    for(int instI = pc; instI != 0; instI++) {

        fetch(instrMem[instI]);

        int branch = decode(IF_ID[3], instI);

        execute(ID_EX[3]);

        accessMem(EX_MEM[3], instI);

        writeBack(MEM_WB[3]);

        /*cout << "===========Registers[" << instI << "]===========" << '\n';
        for (int k = 0; k <= 31; k++) {
            cout << "reg[" << k << "] " << reg[k] << '\n';
        }*/

        // Add word branch to word instI (then instI++)
        instI = branch;

        shadowShift();

        if(instI == 0){
            return 0;
        }
    }
    //printMem();


    return 0;
}