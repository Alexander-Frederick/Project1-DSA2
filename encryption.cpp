#include "encryption.h"

const int ASCIIMIN = 'a';
const int ASCIIMAX = 'z';
int range = ASCIIMAX - ASCIIMIN + 1;

vector<string> encryptPasswords(string key, vector<string> unencryptedPasswords){
    vector<string> encryptedPasswords = {};
    for(int i = 0; i < unencryptedPasswords.size(); i++){
        encryptedPasswords.at(i) = encryptString(key, unencryptedPasswords.at(i));
    }
    return encryptedPasswords;
}
string encryptString(string key, string unencryptedString){
    string encryptedPassword = "";
    for(int i = 0, k = 0; i < unencryptedString.size(); i++){
        k = i % key.size();
        encryptedPassword = encryptedPassword + encryptLetter(key[k], unencryptedString[i]);
    }
    return encryptedPassword;
}
char encryptLetter(char key, char unencryptedLetter){
    char letter;
    unencryptedLetter = unencryptedLetter - ASCIIMIN;
    key = key - ASCIIMIN;
    letter = key + unencryptedLetter;
    letter = letter % range + ASCIIMIN;
    return letter;
}
