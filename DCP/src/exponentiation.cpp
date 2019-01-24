//
// Created by asmu270293 on 23.01.2019.
//

#include <iostream>

long long int getExp(int base, int exp){
    long long int res = 1;
    while(exp!=0){
        if((exp&1)==1){
            res *=base;
        }
        exp >>=1;
        base *=base;
        std::cout<<base<<" "<<exp<<" "<<res<<std::endl;
    }
    return res;
}

int main(){
    std::cout<<getExp(2, 10);
}