#pragma once
#include <queue> //a include file that contains queue

class QueueDS {

    public:

        std::queue<int> q; //a queue that can contain integers

        //adds a new element to end of the queue
        void enqueue(int v){
            { q.push(v); } //adds v to the end of the queue
        }

        //removes an element from the front of the queue
        void dequeue() {
            if (!q.empty()){
                q.pop();
            }
        }
};