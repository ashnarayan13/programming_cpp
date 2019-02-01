//
// Created by asmu270293 on 01.02.2019.
//

#include <iostream>
#include <vector>
#include <algorithm>

bool isPossible(std::vector<int> arr){
    int count = 0;
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i]>arr[i+1]){
            count++;
        }
        if(count>1){
            return false;
        }
    }
    return true;
}

int main(){
    std::vector<int> arr = {4,2,1};
    if(isPossible(arr)){
        std::cout<<"Yes\n";
    }
    else{
        std::cout<<"No\n";
    }
}
