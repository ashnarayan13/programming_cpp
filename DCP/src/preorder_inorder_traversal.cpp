//
// Created by asmu270293 on 28.01.2019.
//

#include <iostream>

struct node{
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
