#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class GetRsrcRdst
{
public:
    string rsrc, rdst;
};

vector<string> universalSplit (string command, char symbol)
{
    stringstream s(command);
    vector<string> v;

    while (getline(s, command, symbol))
        v.push_back(command);

    return v;
}

GetRsrcRdst rsrcRdst(string command)
{
    vector<string> v;
    string rc, st;
    GetRsrcRdst s;
    v = universalSplit (command, ',');  //{{A,D,D},{ ,R,1},{ ,R,2}}

    for (int i=4; i<int(v[0].size()); ++i)   //rc="R1"
        rc.push_back(v[0][i]);

    for (int i=1; i<int(v[1].size()); ++i)   //st="R2"
        st.push_back(v[1][i]);

    s.rsrc = rc;   //rsrc="R1"
    s.rdst = st;   //rdst="R2"

    return s;
}
