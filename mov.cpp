#include <iostream>

using namespace std;

void mov(int dataReg[], int memory[], string rsrc, string rdst, unsigned int flag[])
{
    unsigned int value;
    if (rsrc[0]=='R')  //MOV R1, R0
    {
        //mode = 2;
        value = dataReg[rsrc[1]-'0'];
    }
    else if (rsrc[0]=='[')   //MOV [R1], R3
    {
        //mode = 3;
        value = memory[dataReg[rsrc[2]-'0']];
    }
    else
    {
        //mode =1;
        value = stoi(rsrc);
    }
    int pos = rdst[1]-'0';
    dataReg[pos] = value;
}

/**note: convert char to int by subtracting '0'**/
