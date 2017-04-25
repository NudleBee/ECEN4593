#include <iostream>
#include <fstream>

using namespace std;

int inst, clk, CPI, Ihit, Dhit;
string *instMem;
int c = 0;

int main() {
    string wrd, tmp;
    ifstream program;
    program.open ("../src/Program2File1.txt");
    if (program.is_open()) {
        while (getline(program, tmp)) {
            c = c + 1;
        }
    }
    else cout << "Couldn't open file" << '\n';

    instMem = new string [c];
    program.close();
    cout << c << '\n';

    program.open ("../src/Program2File1.txt");
    if(program.is_open()) {
        int i = 0;
        while (getline(program, wrd, ',')) {
            getline(program, tmp);
            instMem[i] = wrd;
            cout << i << " " << instMem[i] << '\n';
            i++;
        }
    }
    else cout << "Couldn't open file" << '\n';

    return 0;
}