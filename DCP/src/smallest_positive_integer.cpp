//
// Created by Ashwath on 10.11.18.
//

#include <iostream>
#include <algorithm>
#include <vector>

void solve(std::vector<int> array){
    std::sort(array.begin(), array.end());
    int lowest=1;
    for(int i=0; i<array.size(); i++){
        if(array[i]>0){
            if(array[i]!=lowest){
                std::cout<<lowest;
                return;
            }
            else{
                lowest++;
            }
        }
    }
    std::cout<<lowest;
}

int main(){
    std::vector<int> array = {1, 2, 0};
    solve(array);
}