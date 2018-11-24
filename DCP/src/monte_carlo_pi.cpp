//
// Created by Ashwath on 21.11.18.
//

#include <bits/stdc++.h>

int main(){
    double x,y;
    int circle = 0, square = 0;
    std::srand(time(NULL));
    double dist, pi;
    int i = 0;
    for(i=0; i<100*100; i++){
        x = double(std::rand()%(101))/100;
        y = double(std::rand()%(101))/100;
        dist = x*x + y*y;
        if(dist<=1){
            circle++;
        }
        square++;
        pi = double(4*circle)/square;
    }
    std::cout<<"Final - "<<pi<<std::endl;
    return 0;
}