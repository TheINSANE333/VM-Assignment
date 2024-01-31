#include <iostream>

using namespace std;

void out(string line, int dataReg[], unsigned int flag[])
{
    cout << "Screen output: ";

    cout << int(dataReg[line[5]-'0']) << endl;
}

//checked
