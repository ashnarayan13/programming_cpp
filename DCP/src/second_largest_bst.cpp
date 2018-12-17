//
// Created by Ashwath on 14.12.2018.
//

#include <iostream>

struct Node{
    int key;
    Node *left, *right;
};

Node* newNode(int item){
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key){
    if(node == NULL){
        return newNode(key);
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }
    return node;
}

void secondLargestUtil(Node *root, int &c){
    if (root == NULL || c >= 2)
        return;
    // in order traversal;
    secondLargestUtil(root->right, c);
    c++;

    if (c == 2)
    {
        std::cout << "2nd largest element is "
             << root->key << std::endl;
        return;
    }

    // Recur for left subtree
    secondLargestUtil(root->left, c);
}

void secondLargest(Node *root){
    int c = 0;
    secondLargestUtil(root, c);
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);

    secondLargest(root);

    return 0;
}