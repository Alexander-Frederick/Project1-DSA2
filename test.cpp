#include <iostream>
#include <cassert>
#include <iostream>
#include <string>
#include "tokenizer.h"
#include "passwords.h"
#include "encryption.h"

using namespace std;

string fileName = "testName.txt";
string fileRaw = "testRaw.txt";

void test_tokenization(){
    vector<string> expected = {"Alex", "Mary"};
    assert(tokenizeName(fileName) == expected);
    cout << "Tokenizer is able to parse sample" << endl;
}
void test_raw_tokenization(){
    vector<string> expected = {"weather", "angle"};
    assert(tokenizePasswords(fileRaw) == expected);
    cout << "Tokenizer is able to parse passwords" << endl;
}

void test_password_length(){
    bool passwordsAreCorrectLength = true;
    string password = passwordGeneration();

    if(password.size() != 9){
        passwordsAreCorrectLength = false;
    }

    assert(passwordsAreCorrectLength);
    cout << "Generated passwords are the correct length" << endl;
}

void test_password_composition(){
    bool passwordIsLegal = true;
    string password = passwordGeneration();

    for(int i = 0; i < password.size(); i++){
        char charToTest = password[i];
        if(charToTest >= 'a' && charToTest <= 'z'){
            passwordIsLegal = false;
        }
    }

    assert(passwordIsLegal);
    cout << "passwordGeneration creates Passwords with legal lowercase characters" << endl;
}

void test_data_encryption(){

    bool encryptionWorks;
    string unencryptedString = "maryhadalittlelamb";
    string encryptionKey = "fleece";
    string expectedEntcryption = "rlvcjeilpmvxqppeof";

    string testString = encryptString(encryptionKey, unencryptedString);
    assert(testString == expectedEntcryption);

}

