//
// Created by Ashwath on 04.12.2018.
//

#include <iostream>
#include <vector>

struct Node {
    int val;
    Node *next;
};

Node* insert(int val){
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* node){
    std::cout<<node->val;
    if(node->next != NULL)
        printList(node->next);
}

void printNth(Node* node, int n){
    static int i=0;
    if(node==NULL)
        return;
    printNth(node->next, n);
    if(++i == n)
        std::cout<<node->val;
}

void printNthVal(Node* node, int n){
    Node* main = node;
    Node* ref = node;
    int count = 0;
    if(node != NULL){
        while(count<n){
            if(ref == NULL){
                std::cout<<"Nope \n";
                return;
            }
            ref = ref->next;
            count++;
        }

        while(ref!=NULL){
            main = main->next;
            ref = ref->next;
        }
        std::cout<<main->val;
    }
}

int main(){
    Node* new_Node = insert(20);
    new_Node->next = insert(4);
    new_Node->next->next = insert(15);
    new_Node->next->next->next = insert(35);
    //printList(new_Node);
    printNthVal(new_Node, 2);
}

