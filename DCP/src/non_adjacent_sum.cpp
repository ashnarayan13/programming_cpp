//
// Created by Ashwath on 16.11.2018.
//

#include <iostream>
#include <vector>

int get_max_adj(std::vector<int> array){
    int inclusive = array[0];
    int exclusive = 0;
    int exclusive_new;
    for(int i=1; i<array.size(); i++){
        std::cout<<i<<std::endl;
        exclusive_new = (inclusive > exclusive)? inclusive: exclusive;
        std::cout<<"Exclusive new: "<<exclusive_new<<std::endl;
        inclusive = exclusive + array[i];
        std::cout<<"Inclusive: "<<inclusive<<std::endl;
        exclusive = exclusive_new;
        std::cout<<"Exclusive: "<<exclusive<<std::endl;
    }
    return ((inclusive>exclusive)? inclusive: exclusive);
}

int main(){
    int size;
    std::cin>>size;
    std::vector<int> array(size);
    for(int i=0; i<size; i++){
        int temp;
        std::cin>>temp;
        array.push_back(temp);
    }
    std::cout<<get_max_adj(array);
    return 0;
}
