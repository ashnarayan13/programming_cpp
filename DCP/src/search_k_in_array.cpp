#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool get_sum(vector<int> array, int k){
	int l, r;
	sort(array.begin(), array.end());
	l = 0;
	r = array.size()-1;
	while(l<r){
		if((array[l]+array[r])==k){
			cout<<array[l]<<" "<<array[r]<<endl;
			return true;
		}
		else if((array[l]+array[r])<k){
			l++;
		}
		else{
			r--;
		}
	}
	return false;
}

int main() {
	vector<int> array;
	int k, size;
	cin>>size;
	for(int i=0; i<size; i++){
		int temp;
		cin>>temp;
		array.push_back(temp);
	}
	cin>>k;
	cout<<get_sum(array, k);
	return 0;
}