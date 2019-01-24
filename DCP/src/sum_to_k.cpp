//
// Created by Ashwath on 20.12.2018.
//

#include <iostream>
#include <vector>
#include <algorithm>

bool isSubsetSum(std::vector<int> set, int n, int sum)
{
// Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

// If last element is greater than sum, then ignore it
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);

/* else, check if sum can be obtained by any of the following
	(a) including the last element
	(b) excluding the last element */
    return isSubsetSum(set, n-1, sum) ||
           isSubsetSum(set, n-1, sum-set[n-1]);
}

int main(){
    std::vector<int> numbers = {3, 34, 4, 12, 5, 2};
    int target = 9;
    if(isSubsetSum(numbers, numbers.size(), target)){
        std::cout<<"We found a set! \n";
    }
    else{
        std::cout<<"We failed \n";
    }
}