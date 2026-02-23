#pragma once //ensures that it is only included once

#include <vector>

class Stack {
public: //makes the variables accessible from outside the class
    std::vector<int> s; //a kinda dynamic array that stores integers

    //adds new element to the stack
    void push(int v){
        s.push_back(v); //pushes the element at the back of the stack
    }

    //removes the element from the stack
    void pop(){
        if (!s.empty()){
            s.pop_back(); //pops the element from the back of stack
        }
    }
};