/**
 * Tokenizes names and passwords
 *
 * @author Alexander Frederick
 */
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
        cout << "Error could not open file " << fileName << endl;
        return {};
    }
    vector<string> namesOutput;
    string data;
    while(getline(inputFile, data)){
        stringstream extract(data);
        string name;
        extract >> name;
        namesOutput.push_back(name);
    }

    inputFile.close();
    return namesOutput;
}
vector<string> tokenizePasswords(string fileName){
    ifstream inputFile;
    inputFile.open(fileName);
    if(!inputFile.is_open()){
        cout << "Error could not open file " << fileName << endl;
        return {};
    }
    
    vector<string> passwordsOutput;
    string data;
    while(getline(inputFile, data)){
        stringstream extract(data);
        string name, password;
        extract >> name >> password;
        passwordsOutput.push_back(password);
    }
    
    inputFile.close();
    return passwordsOutput;
}