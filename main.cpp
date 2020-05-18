#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <math.h>
#include "minmax.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    Minmax mm;
    string line;
    ifstream myfile ("PA2_dataset.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            mm.insert(std::stoi(line));
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 
    string commands = argv[1];
    cout << commands;
    /*vector<string> result;
    stringstream s_stream(commands);
    while(s_stream.good())
    {
    string substr;
        getline(s_stream, substr, ',');
        result.push_back(substr);
    }

    for(int i = result.size(); i > 0; i--)
    {
        if(result[i].substr(0,5) == "printH")
            mm.printHeap();
        else if(result[i].substr(0,5) == "getMi")
            mm.getMin();
        else if(result[i].substr(0,5) == "getMa")
            mm.getMax();
        else if(result[i].substr(0,5) == "inser")
        {
            mm.insert(mm.getInt(result[i]));
        }
        else if(result[i].substr(0,8) == "deleteMa")
            mm.deleteMax();
        else if(result[i].substr(0,8) == "deleteMi")
            mm.deleteMin();

    }*/

}
