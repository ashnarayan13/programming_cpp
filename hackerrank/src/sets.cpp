#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    std::cin>>Q;
    std::set<int> s;
    for(int i=0; i<Q; i++){
        int y,x;
        std::cin>>y>>x;
        if(1 == y){
            s.insert(x);
        }
        else if(2 == y){
            s.erase(x);
        }
        else if(3 == y){
            set<int>::iterator it = s.find(x);
            if(it == s.end()){
                std::cout<<"No"<<endl;
            }
            else{
                std::cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}
