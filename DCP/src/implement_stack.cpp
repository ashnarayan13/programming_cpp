//
// Created by asmu270293 on 01.02.2019.
//

#include <iostream>
#include <algorithm>

class Stack{
    int top;
public:
    int a[1000];
    Stack(){
        top = -1;
    }
    bool push(int x){
        if(top>=(999)){
            std::cout<<"stack overflow\n";
            return false;
        }
        else{
            a[++top] = x;
            std::cout<<"Success\n";
            return true;
        }
    }
    int pop(){
        if(top<0){
            std::cout<<"Underflow\n";
            return 0;
        }
        else{
            int x = a[top--];
            return x;
        }
    }
    int max(){
        if(top<0){
            std::cout<<"Underflow\n";
            return 0;
        }
        else{
            int max = a[0];
            for(int i=1; i<top+1; i++){
                if(a[i]>max){
                    max = a[i];
                }
            }
            return max;
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout<<s.max()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.pop()<<std::endl;
}