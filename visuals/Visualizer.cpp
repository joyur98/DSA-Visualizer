#include "Visualizer.h"
#include "raylib.h"
#include <queue>

//stack visualization
void Visualizer::DrawStack(const Stack &stackDS) {
    int startX = 600; //thje starting x position
    int startY = 600; //the starting y position
    int barHeight = 40; //height of each stack

    //loop through each elements
    for (size_t i = 0; i < stackDS.s.size(); i++) {
        int y = startY - i * (barHeight + 10); //each element stacked upward with a gap of 10px
        DrawRectangle(startX, y, 60, barHeight, GREEN); //draw the element
        DrawText(TextFormat("%d", stackDS.s[i]), startX + 15, y + 10, 20, WHITE); //draws the value 
    }
}

//queue visualization
void Visualizer::DrawQueue(const QueueDS &queueDS) {
    int startX = 300; //the starting x position
    int startY = 500; //the starting y position
    int barSize = 50; //the size of each square element
    int spacing = 10; //gap between elements

    //use a copy to iterate through the queue
    std::queue<int> qCopy = queueDS.q;
    int idx = 0;
    while (!qCopy.empty()) {
        int val = qCopy.front(); qCopy.pop(); //get a remove front element
        int x = startX + idx * (barSize + spacing); //calculates the x position
        DrawRectangle(x, startY, barSize, barSize, ORANGE); //draw queue element
        DrawText(TextFormat("%d", val), x + 15, startY + 15, 20, WHITE); //draw value
        idx++;
    }
}

//linked list visualization
void Visualizer::DrawLinkedList(Node* head) {
    Node* curr = head; //starts at head of list
    int startX = 300; //the starting x position
    int startY = 400; //the starting y position
    int boxWidth = 50; //the width of each node

    //traversing linked list
    while (curr) {
        //draaws the node as a square
        DrawRectangle(startX, startY, boxWidth, boxWidth, PURPLE);
        //draws the value of the node
        DrawText(TextFormat("%d", curr->value), startX + 15, startY + 15, 20, WHITE);

        //draw arrow to next node if it exists
        if (curr->next)
            DrawLineEx({(float)(startX + boxWidth), (float)(startY + boxWidth / 2)}, //start at right edge of current node
                       {(float)(startX + boxWidth + 50), (float)(startY + boxWidth / 2)} //end at the next node position
                       , 4, BLACK); //line thickness and color

        startX += 100; //move x position for next node
        curr = curr->next; //move to next node
    }
}

//binary tree visualization
void Visualizer::DrawTree(TreeNode* root) {
    if (!root){ //if the tree is empty, do nothing
        return;
    }

    //uses queue for BFS traversal
    std::queue<TreeNode*> q;
    q.push(root); //start with root node

    //goes thru nodes level by level
    while (!q.empty()) {
        TreeNode* n = q.front(); q.pop(); //get next node

        //updates nodes position with smooth animation
        n->pos.Update();

        //draws connections to children first
        if (n->left) {
            DrawLineEx(n->pos.current, n->left->pos.current, 4, DARKBLUE); //line to left child
            q.push(n->left); //add left child to queue
        }
        if (n->right) {
            DrawLineEx(n->pos.current, n->right->pos.current, 4, DARKBLUE); //line to right child
            q.push(n->right); //add right child to queue
        }

        // Draw node as a circle
        DrawCircle(n->pos.current.x, n->pos.current.y, 28, BLUE);
        DrawText(TextFormat("%d", n->val),n->pos.current.x - 7, n->pos.current.y - 8, 20, WHITE); //draw value in the node
    }
}