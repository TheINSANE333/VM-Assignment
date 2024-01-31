#include <iostream>

using namespace std;

void load(int dataReg[], int memory[], char rsrc, string rdst, unsigned int flag[])
{
    unsigned int val;

    if (rdst[0] == '[')
        val = memory[dataReg[rdst[2]-'0']];
    else
        val = memory[stoi(rdst)];

    dataReg[rsrc-'0'] = val;
}
