/**
 * Creates Hashtable
 *
 * @author Alexander Frederick
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"
#include <string>

const int TABLE_SIZE = 10;

class HashTable {
private:
    List** table;
    int tableSize;
    int hashFunction(string userID);

public:
    HashTable(int size);
    ~HashTable();
    void insert(string userID, string encPass);
    Node* search(string userID);
};


#endif