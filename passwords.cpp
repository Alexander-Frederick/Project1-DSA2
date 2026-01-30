#include "passwords.h"

using namespace std;

const int PASSWORDSIZE = 9;
const int ASCIIMIN = 'a';
const int ASCIIMAX = 'z';

vector<string> passwordGenerationSheet(int size){
    vector<string> passwords;

    for(int i = 0; i < size; i++){
        passwords.push_back(passwordGeneration());
    }
    return passwords;
}
string passwordGeneration(){

    string blank = "";
    for(int i = 0; i < PASSWORDSIZE; i++){
        blank = blank + (char)(rand() % (ASCIIMAX - ASCIIMIN + 1) + ASCIIMIN);
    }
    return blank;
}