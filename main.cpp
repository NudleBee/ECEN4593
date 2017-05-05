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

    reg[0] = 0;
    reg[29] = instrMem[0];
    reg[30] = instrMem[1];
    pc = instrMem[5];

    //IF_ID[0] = 0x00001025;

    //shove instruction through a loop
    for(int instI = pc; instI != 0; instI++) {
        reg[0] = 0;
        writeBack(MEM_WB[0]);

        reg[0] = 0;
        accessMem(EX_MEM[0]);

        reg[0] = 0;
        execute(ID_EX[0]);

        reg[0] = 0;
        fetch(instrMem[instI]);

        reg[0] = 0;
        int branch = decode(IF_ID[0], instI);

        //Add word branch to word instI (then instI++)
        instI = branch;

        if(stall == true){
            IF_ID[1] = 0;
            instI--;
            stall = false;
        }

        shadowShift();

        if(instI == 0){
            return 0;
        }

        /*cout << "===========Registers[" << instI << "]===========" << '\n';
        for (int k = 0; k <= 31; k++) {
            cout << "reg[" << k << "] " << reg[k] << '\n';
        }*/
        //printMem();

    }


    return 0;
}