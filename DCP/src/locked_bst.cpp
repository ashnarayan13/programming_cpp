//
// Created by Ashwath on 08.12.18.
//

#include <iostream>

struct Node{
    int val;
    Node* left;
    Node* right;
    bool lock;
};

Node* newNode(int item){
    Node* temp = new Node;
    temp->val = item;
    temp->left = NULL;
    temp->right = NULL;
    temp->lock = false;
    return temp;
}

bool check_child(Node* root, int val)
{
    if (root != NULL)
    {
        std::cout<<root->val<<" Start\n";
        if(!root->lock || root->val == val) {
            //std::cout<<"if "<<root->val<<" "<<root->lock<<std::endl;
            check_child(root->left, val);
            check_child(root->right, val);
        }
        else{
            //std::cout<<"elif "<<root->val<<" "<<root->lock<<std::endl;
            return false;
        }
    }
    return true;

}

Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->val)
        node->left  = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

bool isLocked(Node* root, int val){
    if(root->val < val){
        isLocked(root->right, val);
    }
    else if(root->val > val){
        isLocked(root->left, val);
    }
    else{
        if(root->lock){
            return true;
        }
        else{
            return false;
        }
    }
}

bool lock(Node* root, int val){
    if(root->val < val && !root->lock){
        std::cout<<"if "<<root->val<<" "<<root->lock<<std::endl;
        lock(root->right, val);
    }
    else if(root->val > val && !root->lock){
        std::cout<<"elif "<<root->val<<" "<<root->lock<<std::endl;
        lock(root->left, val);
    }
    else if(root->val == val && !root->lock){
        std::cout<<"Calling child \n";
        if(check_child(root, val))
        {
            root->lock = true;
            return true;
        }
        else{
            //std::cout<<"Cannot lock as children are locked\n";
            return false;
        }
    }
    else{
        std::cout<<"cannot lock \n";
        return false;
    }
}

bool unlock(Node* root, int val){
    if(root->val < val){
        if(root->lock){
            //std::cout<<"Cannot unlock as parent is locked\n";
            return false;
        }
        unlock(root->right, val);
    }
    else if(root->val > val){
        if(root->lock){
            //std::cout<<"Cannot unlock as parent is locked\n";
            return false;
        }
        unlock(root->left, val);
    }
    else{
        if(check_child(root, val))
        {
            root->lock = false;
            return true;
        }
        else{
            //std::cout<<"Cannot unlock as children are locked "<<root->val<<std::endl;
            return false;
        }
    }
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d %d \n", root->val, root->lock);
        inorder(root->right);
    }
}

int main(){
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    printf("\n");

    std::cout<<"Lock \n";
    lock(root, 30);
    std::cout<<"Lock \n";
    lock(root, 50);
    std::cout<<"Lock \n";
    lock(root, 70);
    inorder(root);
    printf("\n");

    std::cout<<"Unlock \n";
    unlock(root,70);
    inorder(root);
}