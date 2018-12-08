//
// Created by Ashwath on 08.12.18.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int editDistance(std::string input, std::string compare){
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    std::transform(compare.begin(), compare.end(), compare.begin(), ::tolower);
    std::vector<int> ip(26,0);
    std::vector<int> op(26,0);
    int answer = 0;
    for (char i : input) {
        ip[(int(i)-int('a'))] += 1;
    }
    for (char i : compare) {
        op[(int(i)-int('a'))] += 1;
    }

    for(int i=0; i<ip.size(); i++){
        if(op[i]!=ip[i]){
            if(op[i]>ip[i])
            answer += op[i]-ip[i];
        }
    }
    return answer;
}

int main(){
    std::string initial = "kitten";
    std::string required = "sitting";
    std::cout<<"Edit distance: "<<editDistance(initial, required)<<std::endl;
}
