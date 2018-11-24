//
// Created by Ashwath on 24.11.18.
//
#include <iostream>

#define MAX 100

class Stack{
private:
    int top;
public:
    int array[MAX];
    Stack(){
        top = -1;
    }
    bool record(int a);
    bool empty();
    int get_last();
};

bool Stack::empty() {
    //if top is -1, stack is empty
    return (top<1);
}

bool Stack::record(int a) {
    if(top>=MAX-1){
        std::cout<<"Stack overflow ;)";
    }
    else{
        array[++top] = a;
        return true;
    }
}

int Stack::get_last() {
    if(top<0){
        std::cout<<"Stack underflow :)";
        return -1;
    }
    else{
        return array[top--];
    }
}

int main(){
    Stack test;
    test.get_last();
    test.record(5);
    test.record(12);
    test.record(4);
    std::cout<<test.get_last()<<std::endl;
    std::cout<<test.get_last()<<std::endl;
    return 0;
}
