//
// Created by Ashwath on 13.12.2018.
//

#include <iostream>
#include <algorithm>
#include <vector>

void getMedian(int num, std::vector<int> &store){
    //std::cout<<"Start\n";
    store.push_back(num);
    std::sort(store.begin(), store.end());
    if(store.size() == 1){
        std::cout<<store[0]<<std::endl;
        return;
    }
    if(store.size()%2 == 0){
        int upper = (store.size()/2);
        int lower = upper-1;
        std::cout<<(store[lower]+store[upper])/2.0f<<std::endl;
    }
    else{
        std::cout<<store[(store.size())/2]<<std::endl;
    }
    /*for(int i=0; i<store.size(); i++){
        std::cout<<store[i]<<" ";
    }
    std::cout<<"\n\n";*/
}

int main(){
    std::vector<int> arr = {2, 1, 5, 7, 2, 0, 5};
    std::vector<int> store;
    for(int i=0; i<arr.size(); i++){
        getMedian(arr[i], store);
    }
}

