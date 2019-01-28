//
// Created by asmu270293 on 28.01.2019.
//

#include <iostream>
#include <string>

class node{
public:
    std::string info;
    node *left = NULL;
    node *right = NULL;
    node(std::string val){
        info = val;
    }

    int toInt(std::string str);
    int eval(node* root);
};

int node::toInt(std::string str){
    int num = 0;
    for(int i=0; i<str.length(); i++){
        num = num*10 + (int(str[i])-48);
    }
    return num;
}

int node::eval(node* root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return toInt(root->info);
    }
    int left = eval(root->left);
    int right = eval(root->right);

    if(root->info=="-"){
        return left-right;
    }
    if(root->info=="+"){
        return left+right;
    }
    if(root->info=="*"){
        return left*right;
    }
    return left/right;
}

int main(){
    node *root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("20");
    std::cout << root->eval(root) << std::endl;

    delete(root);

    root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("/");
    root->right->right->left = new node("20");
    root->right->right->right = new node("2");

    std::cout << root->eval(root);
    return 0;
}