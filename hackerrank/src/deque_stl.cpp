#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> que(k);
    int i=0;
    //first round
    for(i=0; i<k; i++){
        while((!que.empty()) && arr[i]>=arr[que.back()])
            que.pop_back();
        
        que.push_back(i);
    }
    //cout<<"I: "<<i<<endl;
    for(; i<n; i++){
        cout<<arr[que.front()]<<" ";
        while((!que.empty()) && que.front()<=i-k)
            que.pop_front();
        
        while((!que.empty()) && arr[i] >= arr[que.back()])
            que.pop_back();
        que.push_back(i);
    }
    cout<<arr[que.front()]<<endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}