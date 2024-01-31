#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void drawTableLite(string command, int dataReg[], int memory[], unsigned int flag[], unsigned int pc)
{
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

    cout << '+' << "     " << "+-----+" << endl << endl;  // +-----+
}
