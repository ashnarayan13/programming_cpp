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
    int arr[1001];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    for(int i=N-1; i>=0; i--){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
