#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node{
private:
    string userID;
    string encryptedPassword;
    Node* next;

public:
    Node(string user, string encPass);
    string getUser();
    string getEncryptedPassword();
    Node* getNext();
    void setNext(Node* n);


};


#endif