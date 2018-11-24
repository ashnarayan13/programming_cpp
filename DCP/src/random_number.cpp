//
// Created by Ashwath on 24.11.18.
//

#include <iostream>
#include <vector>
#include <time.h>

int pick_rand(int a){
    static int res;
    static int count = 0;
    count++;
    if(count==1){
        res = a;
    }
    else{
        int i= std::rand()%count;
        if(i==count-1){
            res = a;
        }
    }
    return res;
}

int main(){
    std::vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    std::srand(time(NULL));
    for(int i=0; i<a.size(); i++){
        std::cout<<pick_rand(a[i])<<std::endl;
    }
}