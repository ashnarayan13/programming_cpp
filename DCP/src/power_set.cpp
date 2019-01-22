//
// Created by Ashwath on 17.12.2018.
//

#include <iostream>
#include <vector>

void printSet(std::vector<char> sets){
    unsigned int setSize = std::pow(2, sets.size());
    int counter, j;

    for(counter = 0; counter<setSize; counter++){
        for(j=0; j<sets.size(); j++){
            if(counter & (1<<j)){
                //std::cout<<"Entered if \n";
                std::cout<<sets[j];
            }
        }
        std::cout<<std::endl;
    }
}

int main(){
    std::vector<char> sets = {'1','2','3'};
    printSet(sets);
    return 0;
}

