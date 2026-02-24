#include "raylib.h"
#include "ui/UI.h"
#include "structures/Stack.h"
#include "structures/Queue.h"
#include "structures/LinkedList.h"
#include "structures/BinaryTree.h"
#include "visuals/Visualizer.h"

#include <cstdlib>   
#include <ctime>     
#include <algorithm> 
#include <vector>

enum Mode { STACK, QUEUE, LINKED_LIST, TREE };
Mode current = STACK;

//data structures
Stack stackDS;
QueueDS queueDS;
LinkedList listDS;
BinaryTree treeDS;

int main() {
    InitWindow(1200, 700, "DSA Visualizer");
    SetTargetFPS(60);

    //seed random numbers
    std::srand(std::time(nullptr));

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //draw header and sidebar
        DrawHeader("DSA Visualizer");
        DrawSidebar();

        //sidebar buttons
        Button bStack = {{20, 100, 160, 40}, "Stack", current==STACK};
        Button bQueue = {{20, 150, 160, 40}, "Queue", current==QUEUE};
        Button bList  = {{20, 200, 160, 40}, "Linked List", current==LINKED_LIST};
        Button bTree  = {{20, 250, 160, 40}, "Binary Tree", current==TREE};

        if (DrawButton(bStack)) current = STACK;
        if (DrawButton(bQueue)) current = QUEUE;
        if (DrawButton(bList)) current = LINKED_LIST;
        if (DrawButton(bTree)) current = TREE;

        //insert / remove buttons
        Button bInsert = {{20, 330, 160, 40}, "Insert Random"};
        Button bRemove = {{20, 380, 160, 40}, "Remove"};

        if (DrawButton(bInsert)) {
            int val = rand() % 100 + 1; //random number 1-100
            switch(current) {
                case STACK:       stackDS.push(val); break;
                case QUEUE:       queueDS.enqueue(val); break;
                case LINKED_LIST: listDS.insert(val); break;
                case TREE:
                    treeDS.root = treeDS.insertBST(treeDS.root, val, {800, 150});
                    treeDS.updatePositions(treeDS.root, 800, 150);
                    break;
            }
        }

        if (DrawButton(bRemove)) {
            switch(current) {
                case STACK:       stackDS.pop(); break;
                case QUEUE:       queueDS.dequeue(); break;
                case LINKED_LIST: listDS.remove(); break;
                case TREE:        break;
            }
        }

        //sort button
        Button bSort = {{20, 430, 160, 40}, "Sort"};
        if (DrawButton(bSort)) {
            switch(current) {
                case STACK:       std::sort(stackDS.s.begin(), stackDS.s.end()); break;
                case QUEUE: {
                    std::vector<int> temp;
                    while (!queueDS.q.empty()) { temp.push_back(queueDS.q.front()); queueDS.q.pop(); }
                    std::sort(temp.begin(), temp.end());
                    for (auto v : temp) queueDS.q.push(v);
                    break;
                }
                case LINKED_LIST: {
                    std::vector<int> temp;
                    Node* curr = listDS.head;
                    while(curr) { temp.push_back(curr->value); curr = curr->next; }
                    std::sort(temp.begin(), temp.end());
                    listDS.head = nullptr;
                    for (auto v : temp) listDS.insert(v);
                    break;
                }
                case TREE:        break;
            }
        }

        //draw selected data structure
        switch(current) {
            case STACK:       Visualizer::DrawStack(stackDS); break;
            case QUEUE:       Visualizer::DrawQueue(queueDS); break;
            case LINKED_LIST: Visualizer::DrawLinkedList(listDS.head); break;
            case TREE:        Visualizer::DrawTree(treeDS.root); break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}