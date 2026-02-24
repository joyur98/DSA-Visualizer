#pragma once //mmakes sure that this header is only included once

//structucre that represents a node
struct Node {
    int value; //data stored
    Node* next; //pointer to next node

    //constructor which intializes a new node with given value
    Node(int v) : value(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head = nullptr; //the first node in the list

    //insert operation in a linked list
    void insert(int v) {
        //creates a new node with given value
        Node* n = new Node(v);
        if (!head) {
            head = n; //if this node is the first node then it becomes head
        }
        else { //links the new node to previous node
            Node* t = head;
            while (t->next) t = t->next;
            t->next = n;
        }
    }

    //removal operation in a linked list
    void remove() {
        //if the list is empty then quit
        if (!head) {
            return;
        }

        //if there is only one node 
        if (!head->next) { //if the heads next is null pointer
            delete head; //free the memory
            head = nullptr; //sets the head to null pointer so it doesnt point to anything
            return;
        }

        //if there are multiple nodes so we find the second last node
        Node* t = head; //starts from the node

        while (t->next->next){ //runs until the next node has a next node
            t = t->next; //goes to the next node, until the second last node
        }

        delete t->next; //delete the last node
        t->next = nullptr; //set new last nodes next to null pointer
    }
};