#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <string>

class List{

private:
    Node* head;
    Node* findUserHelper(Node* currentNode, string name);

public:
    List();
    ~List();
    void addNode(string userID, string encPass);
    Node* findUser(string name);


};

#endif