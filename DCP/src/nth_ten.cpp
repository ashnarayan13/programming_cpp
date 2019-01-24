//
// Created by priyamash on 22.01.19.
//

#include <iostream>

int findnth(int num){
    int count = 0;
    for(int current = 19; ;current += 9){
        int sum = 0;
        for(int i = current; i>0; i = i/10){
            sum = sum + i%10;
        }
        if(sum == 10){
            count++;
        }
        if(count == num){
            return current;
        }
    }
    return -1;
}
int main(){
    std::cout<<findnth(5);
}