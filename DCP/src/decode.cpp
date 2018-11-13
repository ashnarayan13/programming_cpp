//
// Created by Ashwath on 13.11.18.
//

#include <iostream>
#include <cstring>
#include <vector>

bool are_valid(char i, char j){
    return (i == '1' || (i == '2' && j <= '6'));
}

int decode(std::string s) {
    if(s.size() == 0 || s[0] == '0'){
        return 0;
    }
    if(s.size() == 1){
        return 1;
    }
    std::vector<int> opt(s.size());
    opt[0] = 1;
    if(s[1]!='0' && are_valid(s[0], s[1])){
        opt[1] = 2;
    }
    else{
        opt[1] = 1;
    }
    if(s[1]=='0' && !are_valid(s[0], s[1])){
        return 0;
    }
    for(int i = 2; i < s.size(); i++){
        if(s[i]!='0' && are_valid(s[i-1], s[i])){
            opt[i] = opt[i-1] + opt[i-2];
        }
        if(s[i]!='0' && !are_valid(s[i-1], s[i])){
            opt[i] = opt[i-1];
        }
        if(s[i]=='0' && are_valid(s[i-1], s[i])){
            opt[i] = opt[i-2];
        }
        if(s[i]=='0' && !are_valid(s[i-1], s[i])){
            return 0;
        }
    }
    return opt[s.size()-1];
}
int main(){
    std::string word = "127";
    std::cout<<decode(word);
}

