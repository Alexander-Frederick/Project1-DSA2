#ifndef ENCRYPTION
#define ENCRYPTION
#include <string>
#include <vector>

using namespace std;

vector<string> encryptPasswords(string key, vector<string> unencryptedPasswords);
string encryptString(string key, string unencryptedString);
char encryptLetter(char key, char unencryptedLetter);


#endif