#include <iostream>

using namespace std;

void div(int dataReg[], string rsrc, string rdst, unsigned int flag[])  //ADD R0, R1 or ADD 2, R2
{
    int dataAfter;

    if (rsrc[0] == 'R')
        dataAfter = dataReg[rdst[1]-'0'] /= dataReg[rsrc[1]-'0'];
    else
        dataAfter = dataReg[rdst[1]-'0'] /= stoi(rsrc);

     if (dataAfter == 0) //ZF
        flag[3] = 1;
}
