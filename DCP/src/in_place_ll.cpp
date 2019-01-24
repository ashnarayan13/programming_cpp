//
// Created by asmu270293 on 22.01.2019.
//

#include <iostream>

struct node {
    int data;
    struct node *next;
};

void push(node **head, int k)
{
    node *temp = new node;
    temp->data = k;
    temp->next = *head;
    *head = temp;
}

void print(node *head)
{
    node *curr = head;
    while(curr!=NULL)
    {
        std::cout<<curr->data;
        curr = curr->next;
    }
}

void reverse(node **head)
{
    node *first;
    node *rest;

    /* empty list */
    if (*head == NULL)
        return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head;
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
        return;

    /* reverse the rest list and put the first element at the end */
    reverse(&rest);
    first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    *head = rest;
}

int main()
{
    node *head = NULL;
    push(&head, 7);
    push(&head, 3);
    push(&head, 8);
    push(&head, 6);
    push(&head, 9);

    reverse(&head);

    print(head);

    return 0;
}