#include <iostream>
#include <string>
#include "tokenizer.h"
#include "passwords.h"
#include "filemaker.h"
#include "encryption.h"

using namespace std;

int main(){
    createRawFile("names.txt");
    createEncryptedDataFile("martian", "rawdata.txt");

    return 0;
}