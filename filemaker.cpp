#include "filemaker.h"
#include "tokenizer.h"
#include "passwords.h"
#include "encryption.h"

using namespace std;

void createRawFile(string namesFile){
    ofstream rawFile ("rawdata.txt");
    vector<string> names = tokenizeName(namesFile);
    vector<string> passwords = passwordGenerationSheet(names.size());

    formatFile(rawFile, names, passwords);

    rawFile.close();
}
void createEncryptedDataFile(string key, string rawName){

    ofstream enFile ("encrypteddata.txt");
    vector<string> names = tokenizeName(rawName);
    vector<string> passwords = tokenizePasswords(rawName);
    passwords = encryptPasswords(key, passwords);

    formatFile(enFile, names, passwords);

    enFile.close();
}
void formatFile(ofstream& outputFile, vector<string> names, vector<string> passwords){

    for(int i = 0; i < names.size(); i++){
        outputFile << names[i] << " " << passwords[i] << endl;
    }
}