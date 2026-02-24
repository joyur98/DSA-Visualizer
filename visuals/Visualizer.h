#pragma once // makes it so that this header file is only included once

#include "raylib.h" //raylib header file for graphic functions
#include "structures/Stack.h" //stack data structure header
#include "structures/Queue.h" //queue data structure header
#include "structures/LinkedList.h" //linked List data structure header
#include "structures/BinaryTree.h" //binary Tree data structure header

//functions to draw and visualzie the different data strucutres
class Visualizer {
public:
    static void DrawStack(const Stack &s); //draws a visual representation of a stack
    static void DrawQueue(const QueueDS &q); //draws a visual representation of a queue
    static void DrawLinkedList(Node* head); //draws a visual representation of a linked list
    static void DrawTree(TreeNode* root); //draws a visual representation of a binary tree
};
