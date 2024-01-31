#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void outputfile(char const* file, int dataReg[], int memory[], unsigned int flag[], unsigned int pc)
{
    ofstream cc(file);
    if (cc.fail())
    {
        cout << "\nError in file opening" << endl;
        return;
    }
    cc << "Registers: ";
    for (int x=0; x<7; ++x)
    {
        if (dataReg[x] == -1 && x == 6)
            cc << "0000#";
        else if (dataReg[x] == -1)
            cc << "0000 ";
        else if (x == 6)
            cc << int(dataReg[x]) << "#";
        else
            cc << int(dataReg[x]) << " ";
    }
    cc << endl << "Flag     : ";
    for (int x=0; x<4; ++x)
    {
        if (int(flag[x]) == 0 && x == 3)
            cc << "0#";
        else if (flag[x] == 0)
            cc << "0 ";
        else if (x == 3)
            cc << int(flag[x]) << "#";
        else
            cc << flag[x] << " ";
    }
    cc << endl << "PC       : " << pc;
    cc << endl << endl;
    cc << "Memory:" << endl;
    for (int x=0; x<64; ++x)
    {
        if (memory[x] == -1 && (x+1)%8 == 0)
            cc << "0000" << endl;
        else if (memory[x] == -1)
            cc << "0000 ";
        else if ((x+1)%8 == 0)
            cc << setw(4) << int(memory[x]) << " " << endl;
        else
            cc << setw(4) << int(memory[x]) << " ";
    }
    cc << "#";

    cc.close();
}
