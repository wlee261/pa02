#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <math.h>
#include "minmax.h"
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

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
    vector<string> result;
    //mm.getInt("hello 50");
    commands.erase(std::remove_if(commands.begin(), commands.end(), ::isspace), commands.end());
    
    stringstream s_stream(commands);
    while(s_stream.good())
    {
    string substr;
        getline(s_stream, substr, ',');
        result.push_back(substr);
    }
 
    
    for(int i = 0; i < result.size(); i++)
    {
	
        if(result[i].substr(0,5) == "print")
	{
            mm.printHeap();
	    cout << endl;
	}
        else if(result[i].substr(0,5) == "getMi"){
            //cout << "in main get min";
	    cout << mm.getMin() << endl;
	}
        else if(result[i].substr(0,5) == "getMa")
            cout << mm.getMax() << endl;
        else if(result[i].substr(0,5) == "inser")
        {
	    mm.insert(mm.getInt(result[i]));
            cout << "inserted " <<mm.getInt(result[i]) << endl;
        }
        else if(result[i].substr(0,8) == "deleteMa")
            cout << mm.deleteMax() << endl;
        else if(result[i].substr(0,8) == "deleteMi")
            cout << mm.deleteMin() << endl;

    }

}
