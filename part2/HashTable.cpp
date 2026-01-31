#include "HashTable.h"

HashTable::HashTable(int size) {
    tableSize = size;
    table = new List*[tableSize];
    for(int i = 0; i < tableSize; i++) {
        table[i] = new List();
    }
}

HashTable::~HashTable() {
    for(int i = 0; i < tableSize; i++) {
        delete table[i];
    }
    delete[] table;
}

int HashTable::hashFunction(string userID) {
    int sum = 0;
    for(char c : userID) {
        sum += c;
    }
    return sum % tableSize;
}

void HashTable::insert(string userID, string encPass) {
    int index = hashFunction(userID);
    table[index]->addNode(userID, encPass);
}

Node* HashTable::search(string userID) {
    int index = hashFunction(userID);
    return table[index]->findUser(userID);
}