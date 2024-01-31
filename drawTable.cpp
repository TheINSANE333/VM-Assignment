#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void drawTable(string command, int dataReg[], int memory[], unsigned int flag[], unsigned int pc)
{
    //command
    cout << command << endl;

    //dataReg
    for (int i=0; i<7; ++i)
        cout << "   " << i << setw(5);  //  0  1  2  3  4  5  6

    cout << endl;

    for(int i=0; i<7; ++i)
        cout << "+-----";  //+-----+-----+-----

    cout << '+' << "     " << "+-----+" << endl;  //   +---+

    for (int x=0; x<7; ++x)
    {
        if (dataReg[x] == -1)
            cout << '|' << " " << setw(5);  //|x1   |x2   |
        else
            cout << '|' << int(dataReg[x]) << setw(6-(to_string(int(dataReg[x])).length()));
    }

    cout << '|' << "  " << "PC" << " " << '|' << setw(5) << pc << '|' << endl;  // PC |  pc|

    for(int i=0; i<7; ++i)
        cout << "+-----";  //+-----

    cout << '+' << "     " << "+-----+" << endl;  // +-----+

    //flags
    cout <<"  CF"
        << setw(6) << "OF"
        << setw(6) << "UF"
        << setw(6) << "ZF";  //  CF  OF  UF  ZF

    cout << endl;

    for(int i=0; i<4; ++i)
        cout << "+-----";

    cout << '+' << endl;

    unsigned int cf = flag[0],
        of = flag[1],
        uf = flag[2],
        zf = flag[3];

    if (cf == 0)
        cf = 32;
    else
        cf += '0';
    if (of == 0)
        of = 32;
    else
        of += '0';
    if (uf == 0)
        uf = 32;
    else
        uf += '0';
    if (zf == 0)
        zf = 32;
    else
        zf += '0';

    //setw(6-(to_string(cf).length()))

    cout << '|' << char(cf) << setw(5)
        << '|' << char(of) << setw(5)
        << '|' << char(uf) << setw(5)
        << '|' << char(zf) << setw(5);

    cout << '|' << endl;

    for(int i=0; i<4; ++i)
        cout << "+-----";  //+-----

    cout << '+' << endl;

    //memory
    for(int i=0; i<8; ++i)
        cout << "   " << i << setw(5);  //  0  1  2  3  4  5  6  7

    cout << endl;

    for(int i=0; i<8; ++i)
        cout << "+-----";

    cout << '+' << endl;

    for(int i=1; i<=64; ++i)
    {
        if (i % 8 == 0)
        {
            if (memory[i-1] == -1)
                cout << '|' << " " << setw(5) << '|' << i-1 << endl;
            else
                cout << '|' << int(memory[i-1]) << setw(6-(to_string(memory[i-1]).length())) << '|' << i-1 << endl;
            for(int i=0; i<8; ++i)
                cout << "+-----";
            cout << '+' << endl;
        }
        else
            if (memory[i-1] == -1)
                cout << '|' << " " << setw(5);
            else
                cout << '|' << int(memory[i-1]) << setw(6-(to_string(memory[i-1]).length()));
    }

    for(int i=56; i<64; ++i)
        cout << setw(4) << i << "  ";  // 56 57 58 ... 63

    cout << endl << endl;
}
