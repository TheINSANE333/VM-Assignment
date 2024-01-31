#include <iostream>

using namespace std;

void dec(int dataReg[], char rsrc, unsigned int flag[])
{
    int dataAfter;
    //cout << int(dataReg[rsrc-'0']);
    dataAfter = dataReg[rsrc-'0'] -= 1;

    if (dataReg[rsrc-'0'] == -1)
        dataReg[rsrc-'0'] = 255;

    if (dataAfter == -1)
        flag[2] = 1; // UF

    else if (dataAfter == 0)
        flag[3] = 1;
}
