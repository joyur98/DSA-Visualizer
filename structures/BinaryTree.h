#pragma once
#include "raylib.h" //raylib header file for graphic functions
#include "Animation.h" //an animation header file that i made

//structure for a node in the binary tree
struct TreeNode {
    int val; //data stored in the node
    TreeNode *left, *right; //pointers that points to left and right node
    AnimatedPos pos; // for smooth animation

    //constructor that takes value and assigns position
    TreeNode(int v, Vector2 startPos) : val(v), left(nullptr), right(nullptr) {
        pos.current = pos.target = startPos;
        pos.speed = 8.0f; //animation speed
    }
};

//class that manages binary tree
class BinaryTree {
public: //makes the members accessible from outside the class
    TreeNode* root = nullptr; //pointer to the root node, initially null

    // inserts value to the binary tree
    TreeNode* insertBST(TreeNode* node, int v, Vector2 parentPos) {
        if (!node){ //if empty then create the parent node
        return new TreeNode(v, parentPos);
        }

        float horizontal = 100.f; // base horizontal distance
        float vertical = 80.f;    // vertical distance between levels

        if (v < node->val) { //if value is less than current node, go left
            if (!node->left){ //if left child doesnt exist
                node->left = new TreeNode(v, {node->pos.target.x - horizontal, node->pos.target.y + vertical});
            }
            else{ //if left child exists
                insertBST(node->left, v, node->pos.target); //recursively insert into the left sub tree
            }
            }
        else { //if the value is greater than or equal to, go right
            if (!node->right){ //if right child doesnt exist
                node->right = new TreeNode(v, {node->pos.target.x + horizontal, node->pos.target.y + vertical});
            }
            else{ //if the right child exists
                insertBST(node->right, v, node->pos.target); //recursively enters into the right sub tree
            }
        }
        return node;
    }

    //function to calculate positions based on subtree sizes for better layout
    void updatePositions(TreeNode* node, float x, float y, float horizontalSpacing = 100.f) {
        if (!node){ //if node is null then stop recursion
            return;
        }

        node->pos.target = {x, y}; //set target position for this node

        if (node->left){ //if left child exists
            updatePositions(node->left, x - horizontalSpacing, y + 80.f, horizontalSpacing / 1.5f);
        }
        if (node->right){ //if right child exists
            updatePositions(node->right, x + horizontalSpacing, y + 80.f, horizontalSpacing / 1.5f);
        }
    }
};