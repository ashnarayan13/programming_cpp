//
// Created by Ashwath on 13.11.18.
//

#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* insert(int val){
    Node* newNode = new Node;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool countOptim(Node* root, int &count){
    if (root == NULL)
        return true;

    // Recursively count in left and right subtrees also
    bool left = countOptim(root->left, count);
    bool right = countOptim(root->right, count);

    // If any of the subtrees is not singly, then this
    // cannot be singly.
    if (left == false || right == false)
        return false;

    // If left subtree is singly and non-empty, but data
    // doesn't match
    if (root->left && root->val != root->left->val)
        return false;

    // Same for right subtree
    if (root->right && root->val != root->right->val)
        return false;

    // If none of the above conditions is true, then
    // tree rooted under root is single valued, increment
    // count and return true.
    count++;
    return true;
}

int main(){
    Node *root=NULL;
    root=insert(1);
    root->left=insert(2);
    root->left->left=insert(2);
    root->left->right=insert(2);
    root->left->left->left=insert(5);
    root->left->left->right=insert(5);
    root->right=insert(3);
    root->right->left=insert(3);
    root->right->right=insert(3);
    root->right->left->left=insert(4);
    root->right->left->right=insert(4);
    root->right->right->left=insert(3);
    root->right->right->right=insert(3);

    int counter = 0;
    countOptim(root, counter);
    std::cout<<counter;

    Node* rootN = NULL;
    rootN = insert(0);
    rootN->left = insert(1);
    rootN->right = insert(0);
    rootN->right->left = insert(1);
    rootN->right->left->left = insert(1);
    rootN->right->left->right = insert(1);
    rootN->right->right = insert(0);
    counter = 0;
    countOptim(rootN, counter);
    std::cout<<counter;
}