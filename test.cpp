#include <iostream>
#include <cassert>
#include <iostream>
#include "tokenizer.h"
#include "passwords.h"

using namespace std;

std::string fileName = "testName.txt";

void test_tokenization(){
    std::vector<std::string> expected = {"Alex", "Mary"};
    assert(tokenizeName(fileName) == expected);
    std::cout << "Tokenizer is able to parse sample" << std::endl;
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