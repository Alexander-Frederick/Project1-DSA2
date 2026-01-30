#ifndef FILEMAKER
#define FILEMAKER
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void createRawFile(string fileName);
void createEncryptedDataFile(string key, string rawName);
void formatFile(ofstream& outputFile, vector<string> names, vector<string> passwords);

#endif