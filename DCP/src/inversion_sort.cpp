//
// Created by asmu270293 on 01.02.2019.
//

#include <iostream>
#include <vector>

int getInversions(std::vector<int> arr){
    int k = 0;
    for(uint8_t i=1; i<arr.size(); i++){
        int j;
        int temp = arr[i];
        for(j=i-1; j>=0 && temp<arr[j]; j-- ){
            arr[j+1] = arr[j];
            k++;
        }
        arr[j+1] = temp;
    }
    return k;
}

int main(){
    std::vector<int> arr = {2,4,1,3,5};
    std::cout<<getInversions(arr)<<std::endl;
    std::vector<int> arr_2 = {5, 4, 3, 2, 1};
    std::cout<<getInversions(arr_2)<<std::endl;
}