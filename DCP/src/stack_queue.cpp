//
// Created by asmu270293 on 25.01.2019.
//

#include <stack>
#include <iostream>

class Queue{
private:
    std::stack<int> stack1, stack2;
public:
    void enQueue(int x){
        stack1.push(x);
    }
    int deQueue(){
        if(stack1.empty() && stack2.empty()){
            std::cout<<"Empty!\n";
            exit(0);
        }
        if(stack2.empty()){
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int x = stack2.top();
        stack2.pop();
        return x;
    }
};

int main(){
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    std::cout<<q.deQueue()<<std::endl;
    std::cout<<q.deQueue()<<std::endl;
    std::cout<<q.deQueue()<<std::endl;
    return 0;
}