    #include "List.h"


    List::List(){
        head = nullptr;
    }
    void List::addNode(string userID, string encPass){
        Node* newNode = new Node(userID, encPass);
        if(head == nullptr){
            head = newNode;
        } else {
            newNode->setNext(head);
            head = newNode;
        }
    }
    Node* List::findUserHelper(Node* currentNode, string name){
        if(currentNode == nullptr){
            return nullptr;
        }
        if(currentNode->getUser() == name){
            return currentNode;
        }

        return findUserHelper(currentNode->getNext(), name);
    }
    Node* List::findUser(string name){
        return findUserHelper(head, name);
    }