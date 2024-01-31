#include <iostream>

using namespace std;

void inc(int dataReg[], char rsrc, unsigned int flag[])
{
    int dataAfter;
    dataAfter = dataReg[rsrc-'0'] += 1;

    if (dataReg[rsrc-'0'] == 256)
        dataReg[rsrc-'0'] = 0;

    if (dataAfter == 256)
    {
        flag[3] = flag[1] = flag[0] = 1; // CF
    }
}
