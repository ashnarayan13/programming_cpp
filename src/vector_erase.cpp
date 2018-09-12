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
    std::vector<int> vec;
    for(int i=0; i<N; i++){
        int temp;
        std::cin>>temp;
        vec.push_back(temp);
    }
    int c,d,e;
    std::cin>>c>>d>>e;
    vec.erase(vec.begin()+c-1);
    vec.erase(vec.begin()+d-1, vec.begin()+e-1);
    std::cout<<vec.size()<<endl;
    for(int i=0; i<vec.size(); i++){
        std::cout<<vec[i]<<" ";
    }
    return 0;
}
