//
// Created by Ashwath on 11.11.18.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

std::vector<int> cons(int a, int b){
    std::vector<int> res;
    res.push_back(a);
    res.push_back(b);
    return res;
}

int cdr(std::vector<int> cons_map){
    return cons_map[1];
}

int car(std::vector<int> cons_map){
    return cons_map[0];
}

int main(){
    int a,b;
    std::cin>>a>>b;
    std::cout<<car(cons(a,b));
    std::cout<<cdr(cons(a,b));
}
