//
// Created by Ashwath on 28.11.2018.
//

#include <iostream>
#include <vector>
#include <algorithm>

int findClasses(std::vector<int> arrivals, std::vector<int> dep){
    std::sort(arrivals.begin(), arrivals.end());
    std::sort(dep.begin(), dep.end());
    int answer = 1, result = 1;
    int i=1, j=0;
    while(i<arrivals.size() && j<arrivals.size()){
        if(arrivals[i]<dep[j]){
            answer++;
            i++;
            if(answer>result){
                result = answer;
            }
        }
        else{
            answer--;
            j++;
        }
    }
    return result;
}

int main(){
    std::vector<int> arrivals = {900,940, 950, 1100, 1500, 1800};
    std::vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    std::cout<<findClasses(arrivals, dep)<<std::endl;
    std::vector<int> arrivals_1 = {30,0, 60};
    std::vector<int> dep_1 = {75, 50, 150};
    std::cout<<findClasses(arrivals_1, dep_1)<<std::endl;
}
