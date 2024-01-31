#include <iostream>

using namespace std;

void in(string line, int dataReg[], unsigned int flag[])
{
    int value;
    cout << "User input => ";
    cin >> value;

    if(value > 255) //flag
    {
        flag[0] = 1;
        flag[1] = 1;
        value -= 256;
    }
    else if (value < 0)
    {
        flag[2] = 1;
        value += 256;
    }
    else if (value == 0)
        flag[3] = 1;

    dataReg[line[4]-'0'] = value;
}

//checked
