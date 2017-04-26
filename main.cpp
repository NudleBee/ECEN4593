#include <iostream>
#include "src/initalization.cpp"
#include "src/fetch.cpp"


using namespace std;

int *inst, *clk, *CPI, *Ihit, *Dhit;
extern int pc;

int main() {

    int counter = readFile("../src/Program1File1.txt");

    for(int i = 0; i >= counter; i++){
        int cmd = fetch(i);
    }


    return 0;
}