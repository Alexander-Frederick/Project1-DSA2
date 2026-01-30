#include <iostream>
#include <string>
#include "tokenizer.h"
#include "passwords.h"
#include "filemaker.h"
#include "encryption.h"

using namespace std;

int main(){
    string namesFile, encryptionKey;
    
    cout << "=== Password Encryption System ===" << endl;
    cout << endl;
    
    cout << endl;
    cout << "Generating passwords and creating rawdata.txt..." << endl;
    createRawFile("names.txt");
    
    cout << "Encrypting passwords and creating encrypteddata.txt..." << endl;
    createEncryptedDataFile("martian", "rawdata.txt");

    
    return 0;
}