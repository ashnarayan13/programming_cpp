//
// Created by Ashwath on 27.11.2018.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *getIntersectionNode(Node *headA, Node *headB) {
    Node *cur1 = headA, *cur2 = headB;
    while(cur1->data != cur2->data){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}

Node* insert(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    head1 = insert(3);
    head1->next = insert(7);
    head1->next->next = insert(8);
    head1->next->next->next = insert(10);

    head2 = insert(99);
    head2->next = insert(1);
    head2->next->next = insert(8);
    head2->next->next->next = insert(10);


    struct Node *answer = getIntersectionNode(head1, head2);
    std::cout<<answer->data;


    return 0;
}