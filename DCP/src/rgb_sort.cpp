//
// Created by Ashwath on 13.12.2018.
//

#include <iostream>
#include <algorithm>
#include <vector>

void sort(int arr[], int n){
    for(int i=0; i<n/2; i++){

    }
}

int main(){
    std::vector<char> arr = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    for(int i=0; i<arr.size(); i++){
        std::cout<<arr[i]<<" ";
    }
}