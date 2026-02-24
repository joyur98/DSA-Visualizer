#pragma once // Prevents multiple inclusions of this header file

#include "raylib.h"                 // raylib header file for graphic functions
#include "structures/Stack.h"       // Stack data structure header (for stack visualization)
#include "structures/Queue.h"       // Queue data structure header (for queue visualization)
#include "structures/LinkedList.h"  // Linked List data structure header (for list visualization)
#include "structures/BinaryTree.h"  // Binary Tree data structure header (for tree visualization)

class Visualizer {
public:
    // Static methods - can be called without creating a Visualizer object
    // All methods take const references/pointers (read-only access)
    
    static void DrawStack(const Stack &s);           // Draws a visual representation of a stack
                                                     // Shows elements stacked vertically
    
    static void DrawQueue(const QueueDS &q);         // Draws a visual representation of a queue
                                                     // Shows elements in FIFO order
    
    static void DrawLinkedList(Node* head);          // Draws a visual representation of a linked list
                                                     // Shows nodes connected by arrows
    
    static void DrawTree(TreeNode* root);            // Draws a visual representation of a binary tree
                                                     // Shows nodes with left/right connections
};

// This class centralizes all visualization logic for different data structures
// Static methods make it easy to use: Visualizer::DrawStack(myStack);