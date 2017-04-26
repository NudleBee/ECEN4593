#include <iostream>
#include "src/initalization.cpp"
#include "src/fetch.cpp"


using namespace std;

int inst, clk, CPI, *Ihit, Dhit;
extern int pc;

int main() {

    int counter = readFile("../src/Program1File1.txt");

    for(int pc = 0; pc <= counter; pc++){
        fetch(&pc);
        //cout << cmd << '\n';
    }

    return 0;
}