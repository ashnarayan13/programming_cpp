//
// Created by Ashwath on 16.11.2018.
//

#include <iostream>
#include <chrono>
#include <thread>

int main(){
    int n;
    std::cin>>n;
    std::this_thread::sleep_for(std::chrono::milliseconds(n)); //sleep for n milliseconds
    std::cout<<"Done waiting\n";
    return 0;
}