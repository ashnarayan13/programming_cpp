//
// Created by Ashwath on 08.12.18.
//

#include <bits/stdc++.h>

std::string encode(std::string input){
    std::string output;
    char start = input[0];
    int count = 1;
    for(int i=1; i<input.length(); i++){
        if(input[i]!=start){
            output = output + std::to_string(count) + start;
            start = input[i];
            count = 1;
        }
        else{
            count++;
        }
    }
    // last character set
    output = output + std::to_string(count) + start;
    return output;
}

int main(){
    std::string input = "AAAABBBCCDAA";
    std::cout<<"Encoded: "<<encode(input);
}