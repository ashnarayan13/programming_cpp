//
// Created by Ashwath on 12.11.18.
//

#include <iostream>

// default node struct
struct Node {
    int val;
    Node* npx;
};

// XOR operation that returns a Node type. ** convert Node*
// to uintptr_t before XOR operation
Node* XOR(Node* a, Node* b){
    return (Node*)((uintptr_t)a^(uintptr_t)b);
}

// create a new Node and set val to node->val
// node->npx is the XOR of the current head and NULL (node is added to the end)
// if head is not empty (not first element)
// the pointer to next node is XOR(current->npx, NULL) followed by
// updating the npx of the head with new node and the next node
void insert(Node* &head, int val){
    Node* node = new Node;
    node->val = val;
    node->npx = XOR(head, NULL);

    if(head != NULL){
        Node* next = XOR(head->npx, NULL);
        head->npx = XOR(node, next);
    }
    head = node;
}

// iterate over the LL using the XOR function between nodes
void read(Node* head){
    Node *curr = head;
    Node *prev = NULL;
    Node *next;
    while(curr != NULL){
        std::cout<<curr->val<<std::endl;
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
}

int main ()
{
    /* Create following Doubly Linked List
    head-->40<-->30<-->20<-->10 */
    struct Node *head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    // print the created list
    read(head);

    return (0);
}