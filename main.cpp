// *******************
// Program: TC3L_T12L_07.cpp
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Lecture Class: TC3L
// Tutorial Class: T12L
// Trimester: 2310
// Member_1: 1211106628 | KENG JING LI  | 1211106628@STUDENT.MMU.EDU.MY | 01160798623
// Member_2: 1211106818 | LEE XIANG ZE  | 1211106818@STUDENT.MMU.EDU.MY | 01163388308
// Member_3: 1211106586 | NGO SHUN HONG | 1211106586@STUDENT.MMU.EDU.MY | 0197586016
// Member_4: 1211106319 | YEOH HAN YI   | 1211106319@STUDENT.MMU.EDU.MY | 0125568050
// *******************
// Task Distribution
// Member_1: in, out, load, store, mov
// Member_2: drawTable, decToBin, rsrcRdst, writeIntoFile
// Member_3: rol, ror, shl, shr
// Member_4: flags, add, mul, div, sub, inc, dec
// *******************

#include <iostream>
#include <fstream>
#include "hello.h"

using namespace std;

string trim(string s);
string trimRight(string s);

int dataReg[7];
int memory[64];
unsigned int flag[4];  //{CF, OF, UF, ZF}
unsigned int pc = 0;
GetRsrcRdst result;
rorRol finalAns;

void emptyArr()
{
    int i=0;
    while (i<7)    //empty datareg
    {
        dataReg[i] = -1;
        ++i;
    }

    i = 0;

    while (i<64)    //empty memory
    {
        memory[i] = -1;
        ++i;
    }
}

void openFile(ifstream& infile, string filename)
{
    infile.open(filename);

    if(infile.fail())
    {
        cout << "Error mesage: file is not found" << endl;
        exit(EXIT_FAILURE);
    }
}

void readProgram(ifstream& infile, vector<string>& asmProgram)
{
    string line;
    while(getline(infile, line))
    {
        asmProgram.emplace_back(line);
    }
}

/*void printAsmProgram(const vector<string>& asmProgram)
{
    int count = 0;
    for (auto line : asmProgram)
    {
        count++;
        cout << count << ": " << line << endl;
    }
    cout << endl;
}*/

void process(vector<string> asmProgram)
{
    int q=0;

    for(auto line : asmProgram)
    {
        flag[0] = flag[1] = flag[2] = flag[3] = 0;
        ++q;
        if (line.substr(0, 3) == "IN ")
        {
            //command
            cout << line << endl;

            in(line, dataReg, flag);
            pc++;
            drawTableLite(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "OUT")
        {
            //command
            cout << line << endl;

            out(line, dataReg, flag);
            pc++;
            drawTableLite(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "MOV")
        {
            result = rsrcRdst(line);
            mov(dataReg, memory, result.rsrc, result.rdst, flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "ADD")
        {
            result = rsrcRdst(line);
            add(dataReg, result.rsrc, result.rdst, flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "SUB")
        {
            result = rsrcRdst(line);
            sub(dataReg, result.rsrc, result.rdst, flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "MUL")
        {
            result = rsrcRdst(line);
            mul(dataReg, result.rsrc, result.rdst, flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "DIV")
        {
            result = rsrcRdst(line);
            div(dataReg, result.rsrc, result.rdst, flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "INC")
        {
            inc(dataReg, line[5], flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "DEC")
        {
            dec(dataReg, line[5], flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 5) == "STORE")
        {
            result = rsrcRdst(line);
            store(dataReg, memory, line[7], result.rdst, flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 4) == "LOAD")
        {
            result = rsrcRdst(line);
            load(dataReg, memory, line[6], result.rdst, flag);
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "ROR")
        {
            result = rsrcRdst(line);
            finalAns = ror(dataReg, line[5], result.rdst);
            finalAns = binToDec();
            dataReg[line[5]-'0'] = finalAns.decimal;
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0, 3) == "ROL")
        {
            result = rsrcRdst(line);
            finalAns = rol(dataReg, line[5], result.rdst);
            finalAns = binToDec();
            dataReg[line[5]-'0'] = finalAns.decimal;
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0,3) == "SHL")
        {
            result = rsrcRdst(line);
            finalAns = shl(dataReg, line[5], result.rdst);
            finalAns = binToDec();
            dataReg[line[5]-'0'] = finalAns.decimal;
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else if (line.substr(0,3) == "SHR")
        {
            result = rsrcRdst(line);
            finalAns = shr(dataReg, line[5], result.rdst);
            finalAns = binToDec();
            dataReg[line[5]-'0'] = finalAns.decimal;
            pc++;
            drawTable(line, dataReg, memory, flag, pc);
        }
        else
        {
            cout << "Unknown command at line " << q << endl;
            exit(EXIT_FAILURE);
        }
    }
}

int main()
{
    vector<string> asmProgram;

    //string filename = "fileinput1.asm";
    //string filename = "fileinput2.asm";  //user input => 69
    string filename = "fileinput3.asm";
    //string filename = "fileinput4.asm";

    ifstream infile;
    ofstream outfile;

    openFile(infile, filename);

    emptyArr();

    readProgram(infile, asmProgram);

    //printAsmProgram(asmProgram);

    process(asmProgram);

    //outputfile("fileOutput1.txt", dataReg, memory, flag, pc);
    //outputfile("fileOutput2.txt", dataReg, memory, flag, pc);
    outputfile("fileOutput3.txt", dataReg, memory, flag, pc);
    //outputfile("fileOutput4.txt", dataReg, memory, flag, pc);


    infile.close();
    outfile.close();

    //system("pause");

    return 0;
}

string trimLeft(string s)
{
    for (int c=0; c<int(s.length()); ++c)
    {
        if (s[0] == ' ')
        {
            s.erase(0, 1);
        }
    }

    return s;
}

string trimRight(string s)
{
    for (int c=s.length()-1; c>=0; --c)
    {
        if (s[s.length()-1] == ' ')
        {
            s.erase(s.length()-1, 1);
        }
    }

    return s;
}

string trim(string s)
{
    s = trimLeft(s);
    s = trimRight(s);

    return s;
}
