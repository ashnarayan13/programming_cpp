//
// Created by asmu270293 on 28.01.2019.
//

#include <iostream>
#include <vector>

int largest_contiguous_sum(std::vector<int> arr){
    int max_overall = 0;
    int max_current = 0;
    for(int i=0; i<arr.size(); i++){
        max_current = max_current + arr[i];
        if(max_overall<max_current){
            max_overall = max_current;
        }
        if(max_current < 0){
            max_current = 0;
        }
    }
    return max_overall;
}

int main(){
    std::vector<int> array = {34, -50, 42, 14, -5, 86};
    std::cout<<largest_contiguous_sum(array);
    return 0;
}