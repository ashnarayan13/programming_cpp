#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    std::vector<int> vec;
    for(int i=0; i<N; i++){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    std::sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++){
        std::cout<<vec[i]<<" ";
    }
    return 0;
}
