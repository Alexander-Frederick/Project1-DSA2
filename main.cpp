#include <iostream>
#include <string>
#include <iomanip>
#include "tokenizer.h"
#include "passwords.h"
#include "filemaker.h"
#include "encryption.h"
#include "HashTable.h"

using namespace std;

HashTable populateHashTable(string encFile);
void testLegalPasswords(HashTable& hashTable, vector<string>& rawNames, vector<string>& rawPasswords, int testIndices[], int numTests, string key);
void testIllegalPasswords(HashTable& hashTable, vector<string>& rawNames, vector<string>& rawPasswords, int testIndices[], int numTests, string key);

int main(){
    string namesFile = "names.txt";
    string rawFile = "rawdata.txt";
    string encFile = "encrypteddata.txt";
    string key = "riddle";

    createRawFile(namesFile);
    createEncryptedDataFile(key, rawFile);

    HashTable hashTable = populateHashTable(encFile);

    vector<string> rawNames = tokenizeName(rawFile);
    vector<string> rawPasswords = tokenizePasswords(rawFile);

    int testIndices[] = {0, 2, 4, 6, 8};
    int numTests = sizeof(testIndices) / sizeof(testIndices[0]);

    testLegalPasswords(hashTable, rawNames, rawPasswords, testIndices, numTests, key);
    testIllegalPasswords(hashTable, rawNames, rawPasswords, testIndices, numTests, key);

    return 0;
}

HashTable populateHashTable(string encFile) {
    vector<string> encNames = tokenizeName(encFile);
    vector<string> encPasswords = tokenizePasswords(encFile);
    //Make the table more effecient
    float tableExpansion = 1.3;
    
    int tableSize = encNames.size() * tableExpansion;
    HashTable hashTable(tableSize);
    
    for(int i = 0; i < (int)encNames.size(); i++) {
        hashTable.insert(encNames[i], encPasswords[i]);
    }
    
    return hashTable;
}

void testLegalPasswords(HashTable& hashTable, vector<string>& rawNames, vector<string>& rawPasswords, int testIndices[], int numTests, string key) {
    cout << "Legal:" << endl;
    cout << left << setw(15) << "Userid" << setw(20) << "Password(file)" 
         << setw(20) << "Password(table/un)" << "Result" << endl;

    for(int i = 0; i < numTests; i++){
        int idx = testIndices[i];
        string userid = rawNames[idx];
        string passwordFromFile = rawPasswords[idx];
        
        Node* found = hashTable.search(userid);
        if(found != nullptr) {
            string encryptedFromTable = found->getEncryptedPassword();
            string encryptedFromFile = encryptString(key, passwordFromFile);
            
            string result = (encryptedFromFile == encryptedFromTable) ? "match" : "no match";
            
            cout << left << setw(15) << userid << setw(20) << encryptedFromFile 
                 << setw(20) << encryptedFromTable << result << endl;
        }
    }
    cout << endl;
}

void testIllegalPasswords(HashTable& hashTable, vector<string>& rawNames, vector<string>& rawPasswords, int testIndices[], int numTests, string key) {
    cout << "Illegal:" << endl;
    cout << left << setw(15) << "Userid" << setw(20) << "Password(mod)" 
         << setw(20) << "Password(table)" << "Result" << endl;

    for(int i = 0; i < numTests; i++){
        int idx = testIndices[i];
        string userid = rawNames[idx];
        string originalPassword = rawPasswords[idx];
        
        // Modify the first letter of the password to make it illegal
        string modifiedPassword = originalPassword;
        modifiedPassword[0] = 'z';
        
        Node* found = hashTable.search(userid);
        if(found != nullptr) {
            string encryptedFromTable = found->getEncryptedPassword();
            string encryptedFromModified = encryptString(key, modifiedPassword);
            
            string result = (encryptedFromModified == encryptedFromTable) ? "match" : "no match";
            
            cout << left << setw(15) << userid << setw(20) << encryptedFromModified 
                 << setw(20) << encryptedFromTable << result << endl;
        }
    }
}