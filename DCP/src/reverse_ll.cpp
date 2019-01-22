//
// Created by Ashwath on 16.12.18.
//

#include <iostream>
#include <vector>

struct node{
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LL{
public:
    node *head;
    LL(){
        head = NULL;
    }

    void reverse()
    {
        node *current = head;
        node *prev = NULL;
        node *next = NULL;
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void print(){
        node *temp = head;
        while(temp!=NULL){
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void push(int data){
        node *temp = new node(data);
        temp->next = head;
        head = temp;
    }
};


int main(){
    LL ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    std::cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    std::cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}