//
// Created by priyamash on 22.01.19.
//

#include <iostream>
#include <algorithm>

long getLargestProd(std::vector<int> input){
    std::sort(input.begin(), input.end());
    long product1 = input[input.size()-1]*input[input.size()-2]*input[input.size()-3];
    long product2 = 1;
    for(int i=0; i<input.size(); i++){
        if(input[i]>0 && i>=2){
            product2 = input[i]*input[0]*input[1];
        }
    }
    return (product1>product2?product1:product2);
}

int main(){
    std::vector<int> numbers = {-10, 5, -2, -10};
    std::cout<<getLargestProd(numbers);
}