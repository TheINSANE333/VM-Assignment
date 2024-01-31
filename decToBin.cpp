#include <iostream>
#include <cmath>

using namespace std;

class rorRol
{
public:
    unsigned int binary[8];
    unsigned int temp[8];
    unsigned int decimal;
};

rorRol decToBin(int value)
{
    rorRol a;
    for(int i=7; i>=0; --i)
    {
        if (value%2==0)
            a.binary[i]=0;
        else if(value%2==1)
            a.binary[i]=1;
        value/=2;
    }

    return a;
}

rorRol binToDec()
{
    rorRol a;
    a.decimal = 0;
    int x=0;

    for (int i=7; i>=0; --i)
    {
        a.decimal += pow(2, x) * a.temp[i];    //2^0 * temp[7]
        x++;
    }

    return a;
}
