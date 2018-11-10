//
// Created by Ashwath on 10.11.18.
//

#include <iostream>
#include <vector>

struct Node {
    int val;
    Node * left;
    Node * right;
};

Node* newNode(int key){
    Node* temp = new Node;
    temp->val = key;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void serialize(Node *root, std::vector<int> &tree){
    if(root == nullptr){
        tree.push_back(-1);
        return;
    }
    tree.push_back(root->val);
    serialize(root->left, tree);
    serialize(root->right, tree);
}

void deserialize(Node *&root, std::vector<int> &tree, int &i){
    if(i>=tree.size() || tree[i]==-1){
        i=i+1;
        return;
    }
    root = newNode(tree[i]);
    i = i+1;
    deserialize(root->left, tree, i);
    deserialize(root->right, tree, i);
}

void inorderTraversal(Node *root){
    if(root){
        inorderTraversal(root->left);
        std::cout<<root->val<<std::endl;
        inorderTraversal(root->right);
    }
}

int main(){
    struct Node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    std::vector<int> tree;
    int i=0;
    serialize(root, tree);
    struct Node *root1 = nullptr;
    deserialize(root1, tree, i);
    inorderTraversal(root1);
}