#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int i=0; i<N; i++){
        std::cin>>vec[i];
    }
    int Q;
    std::cin>>Q;
    std::vector<int>::iterator it;
    for(int i=0; i<Q; i++){
        int temp;
        std::cin>>temp;
        std::vector<int>::iterator l = std::lower_bound(vec.begin(), vec.end(), temp);
        if(vec[l - vec.begin()] == temp){
            std::cout<<"Yes "<<(l-vec.begin()+1)<<endl;
        }
        else{
            std::cout<<"No "<<(l-vec.begin()+1)<<endl;
        }
    }
    return 0;
}
