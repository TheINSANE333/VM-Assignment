#include <iostream>
#include "hello.h"

using namespace std;

rorRol ror(int dataReg[], unsigned char rsrc, string rdst)
{
    int shift = stoi(rdst);

    shift = shift % 8;

    rorRol a;    //binary[]
    a = decToBin(dataReg[rsrc-'0']);

    for (int i=0; i<=7; ++i)
    {
        if (i+shift <= 7)
            a.temp[i+shift] = a.binary[i];
        else
            break;
    }

    for (int i=0; i<=shift-1; ++i)
        a.temp[i] = a.binary[i+(8-shift)];

    return a;
}

