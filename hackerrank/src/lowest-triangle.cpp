#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a,b;
    cin>>b>>a;
    int i=1;
    while((0.5)*b*i < a){
        i++;
    }
    cout<<i<<endl;
    return 0;
}