#include <iostream>

using namespace std;

void store(int dataReg[], int memory[], char rsrc, string rdst, unsigned int flag[])
{
    unsigned int val=dataReg[rsrc-'0'];

    if (rdst[0] == '[')
        memory[dataReg[rdst[2]-'0']] = val;
    else
        memory[stoi(rdst)] = val;
}
