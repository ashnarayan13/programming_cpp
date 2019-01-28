//
// Created by asmu270293 on 28.01.2019.
//

#include <iostream>
#include <vector>

void bestStock(std::vector<int> stock){
    if(stock.size() == 1){
        return;
    }
    int pairs = 0;
    std::vector<int> buy;
    std::vector<int> sell;
    int max = 0;

    int index = 0;
    while(index<stock.size()-1){
        while(index<stock.size()-1 && stock[index+1]<=stock[index]){
            index++;
        }
        if(index == stock.size()-1){
            break;
        }
        buy.push_back(index++);

        while(index<stock.size() && stock[index]>=stock[index-1]){
            index++;
        }
        //sol[index][1] = index-1;
        sell.push_back(index-1);
        pairs++;
    }
    if(pairs>0){
        for(int i=0; i<buy.size(); i++){
            if(max<stock[sell[i]]-stock[buy[i]]){
                max = stock[sell[i]]-stock[buy[i]];
            }
        }
    }
    std::cout<<max;
}

int main(){
    std::vector<int> stocks = {9, 11, 8, 5, 7, 10};
    bestStock(stocks);
    return 0;
}