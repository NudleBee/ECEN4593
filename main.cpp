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
    reg[29] = mainMemory[0];
    reg[30] = mainMemory[1];
    pc = mainMemory[5];

    //shove instruction through a loop
    for(int instI = pc; instI != 0; instI++) {
        reg[0] = 0;
        fetch(mainMemory[instI]);

        reg[0] = 0;
        int branch = decode(IF_ID[0], instI);

        reg[0] = 0;
        execute(ID_EX[0]);

        reg[0] = 0;
        accessMem(EX_MEM[0]);

        reg[0] = 0;
        writeBack(MEM_WB[0]);

        //Add word branch to word instI (then instI++)
        instI = branch;


        //Forwarding EX_MEM
        if(EX_MEM[1].rd != 0) {
            if (EX_MEM[1].rd == ID_EX[1].rs) {
                ID_EX[1].rs = EX_MEM[1].exOutput;
                cout << "EX/MEM forward" << '\n';
            }
            if (EX_MEM[1].rd == ID_EX[1].rt) {
                stall = true;
                ID_EX[1].rt = EX_MEM[1].exOutput;
                cout << "EX/MEM forward" << '\n';
            }
        }

        //Forward MEM_WB
        if(MEM_WB[1].rd != 0) {
            if(ID_EX[1].rd != ID_EX[1].rs) {
                if (EX_MEM[1].rd == ID_EX[1].rs) {
                    cout << "MEM/WB forward" << '\n';
                    ID_EX[1].rs = MEM_WB[1].memOutput;
                }
            }
            if (ID_EX[1].rd != ID_EX[1].rt) {
                if (EX_MEM[1].rd == ID_EX[1].rt) {
                    ID_EX[1].rt = MEM_WB[1].memOutput;
                    cout << "MEM/WB forward" << '\n';
                }
            }

        }

        //Stall
        if(stall == true) {
            //IF_ID[1] = 0;
            instI--;
        }

        shadowShift();

        if(instI == 0) {
            return 0;
        }
        //printMem();

        /*cout << "===========Registers[" << instI << "]===========" << '\n';
        for (int k = 0; k <= 31; k++) {
            cout << "reg[" << k << "] " << reg[k] << '\n';
        }*/

    }


    return 0;
}