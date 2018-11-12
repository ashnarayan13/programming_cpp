#include <iostream>
#include <vector>
using namespace std;

vector<int> get_products(vector<int> array){
	vector<int> results(array.size());
	vector<int> left(array.size());
	vector<int> right(array.size());
	left[0] = 1;
	right[array.size()-1] = 1;
	for(int i=1; i<array.size(); i++){
		left[i] = array[i-1]*left[i-1];
	}
	for(int i=array.size()-2; i>=0; i--){
		right[i] = array[i+1]*right[i+1];
	}
	for(int i=0; i<array.size(); i++){
		results[i] = left[i]*right[i];
	}
	return results;
}

int main() {
	// your code goes here
	vector<int> array;
	int size;
	cin>>size;
	for(int i=0; i<size; i++){
		int temp;
		cin>>temp;
		array.push_back(temp);
	}
	vector<int> solution = get_products(array);
	for(int i=0; i<solution.size(); i++){
		cout<<solution[i]<<" ";
	}
	return 0;
}