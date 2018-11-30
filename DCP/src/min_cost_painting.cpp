//
// Created by Ashwath on 30.11.2018.
//

#include <iostream>
#include <vector>

#define MAX 10000

int getMin(std::vector<std::vector<int>> costs){
    if(costs.size() == 0){
        return 0;
    }
    int premin = 0;
    int presecond = 0;
    int preindex = -1;
    for(int i=0; i<costs.size(); i++){
        int currMin = MAX;
        int currSec = MAX;
        int currIndex = 0;

        for(int j=0; j<costs[0].size(); j++){
            // if the lowest value is at same index as previous. Take the second min for the previous.
            if(preindex == j){
                costs[i][j] += presecond;
            }
            // Else, just add the cost (doesn't affect the adjacent house rule)
            else{
                costs[i][j] += premin;
            }
            if(currMin>costs[i][j]){
                currSec = currMin;
                currMin = costs[i][j];
                currIndex = j;
            }
            else if(currSec>costs[i][j]){
                currSec = costs[i][j];
            }
        }
        //std::cout<<currMin<<std::endl;
        premin = currMin;
        presecond = currSec;
        preindex = currIndex;
    }
    int ans = MAX;
    for(int j=0; j<costs[0].size(); j++){
        if(ans > costs[costs.size()-1][j]){
            ans = costs[costs.size()-1][j];
        }
    }
    /*for(int i=0; i<costs.size(); i++){
        for(int j=0; j<costs[0].size(); j++){
            std::cout<<costs[i][j]<<" ";
        }
        std::cout<<std::endl;
    }*/
    return ans;
}

int main(){
    std::vector<std::vector<int>> costs {{2,1,6,5},
                                         {5,1,4,5},
                                         {1,2,3,4},
                                         {4,3,2,1},
                                         {5,6,1,2}};
    std::cout<<getMin(costs);
}