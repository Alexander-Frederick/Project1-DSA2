#include "tokenizer.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

vector<string> tokenizeName(string fileName){
    ifstream inputFile;
    inputFile.open(fileName);
    if(!inputFile.is_open()){
        cout << "Error" << endl;
        return;
    }
    vector<string> namesOutput;
    string data;
    while(getline(inputFile, data)){
        stringstream extract(data);
        string name;
        extract >> name;
        namesOutput.push_back(name);
    }

    return namesOutput;
}