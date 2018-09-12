#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::map<std::string, int>m;
    int Q;
    std::cin>>Q;
    for(int i=0; i<Q; i++){
        int ch,y;
        std::string x;
        std::cin>>ch;
        if(ch==1){
            cin>>x>>y;
            std::map<std::string, int>::iterator it = m.find(x);
            if(it==m.end()){
                m.insert(make_pair(x,y));
            }
            else{
                it->second+=y;
            }
        }
        else if(ch==2){
            cin>>x;
            m.erase(x);
        }
        else if(ch==3){
            cin>>x;
            std::map<std::string,int>::iterator it = m.find(x);
            if(it == m.end()){
                std::cout<<"0"<<std::endl;
            }
            else{
                std::cout<<it->second<<std::endl;
            }
        }
    }
    return 0;
}
