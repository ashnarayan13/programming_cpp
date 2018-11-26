//
// Created by Ashwath on 26.11.18.
//
// http://www.cplusplus.com/reference/deque/deque/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> getMax(vector<int> array, int k){
	deque<int> q(k);
	vector<int> ans;
	int i;
	for(i=0; i<k; i++){
		while((!q.empty())&& array[i]>=array[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}
	for(; i<array.size(); i++){
		ans.push_back(array[q.front()]);
		while((!q.empty())&& q.front()<=i-k){
			q.pop_front();
		}
		while((!q.empty())&& array[i]>=array[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}
	ans.push_back(array[q.front()]);
	return ans;
}

int main() {
	// your code goes here
	vector<int> arr = {10,5,2,7,8,7};
	int k=3;
	vector<int> ans = getMax(arr, k);
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}