#include <iostream>
#include "hello.h"

using namespace std;

rorRol shl(int dataReg[], unsigned char rsrc, string rdst)
{
    int shift = stoi(rdst);

    shift = shift % 8;

    rorRol a;    //binary[]
    a = decToBin(dataReg[rsrc-'0']);

    for (int i=7; i>=0; --i)
    {
        if (i-shift >= 0)
            a.temp[i-shift] = a.binary[i];
        else
            break;
    }

    for (int i=7; i>7-shift; --i)
        a.temp[i] = 0;

    return a;
}
