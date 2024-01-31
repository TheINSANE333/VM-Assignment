#include <iostream>

using namespace std;

void sub(int dataReg[], string rsrc, string rdst, unsigned int flag[])  //ADD R0, R1 or ADD 2, R2
{
    int dataAfter,dataBefore;
    dataBefore = dataReg[rdst[1]-'0'];

    if (rsrc[0] == 'R')
        dataAfter = dataReg[rdst[1]-'0'] -= dataReg[rsrc[1]-'0'];
    else
        dataAfter = dataReg[rdst[1]-'0'] -= stoi(rsrc);

    while (dataReg[rdst[1]-'0'] < 0)
        dataReg[rdst[1]-'0'] += 256;

    if (dataAfter == 0) //ZF
        flag[3] = 1;

    if (dataAfter < 0)
        flag[2] = 1; // UF
}

