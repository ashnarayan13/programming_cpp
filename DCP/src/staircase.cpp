//
// Created by Ashwath on 18.11.18.
//

#include <iostream>
#include <vector>

int fibonacci(int n, std::vector<int> m){
    if(n<=1){
        return n;
    }
    int res = 0;

    for(int i=0; i<m.size(); i++){
        res += fibonacci(n-m[i], m);
    }
    return res;
}

int countWays(int s, std::vector<int> m){
    return fibonacci(s+1, m);
}

int main ()
{
    int s = 4;
    std::vector<int> m = {1,2};
    printf("Nuber of ways = %d", countWays(s, m));
    return 0;
}