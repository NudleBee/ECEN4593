#include <iostream>
#include "src/fetch.cpp"


using namespace std;

int *inst, *clk, *CPI, *Ihit, *Dhit;

int main() {

    int counter = readFile("Program1File1.txt");

    for(int i = 0; i >= counter; i++){
        string cmd = fetch(i);
    }


    return 0;
}