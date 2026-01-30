#include "Node.h"

Node::Node(string user, string encPass) {
    userID = user;
    encryptedPassword = encPass;
    next = nullptr;
}

string Node::getUser() {
    return userID;
}

string Node::getEncryptedPassword() {
    return encryptedPassword;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* n) {
    next = n;
}