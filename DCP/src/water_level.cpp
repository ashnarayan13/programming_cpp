//
// Created by Ashwath on 08.12.18.
//

#include <iostream>
#include <bits/stdc++.h>

int findWater(int arr[], int n){
    int left[n];
    int right[n];
    left[0] = arr[0];
    int water_level = 0;
    int water_max = 0;

    for(int i=1; i<n; i++){
        left[i] = std::max(left[i-1],arr[i]);
    }

    right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = std::max(right[i+1], arr[i]);
    }


    for(int i=0; i<n; i++){
        water_level += std::min(left[i], right[i]) - arr[i];
        if((std::min(left[i], right[i]) - arr[i])>=water_max){
            water_max = std::min(left[i], right[i]) - arr[i];
        }
    }

    std::cout<<"Max water level ="<<water_max<<std::endl;
    return water_level;
}

int main(){
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Maximum water that can be accumulated is "
         << findWater(arr, n);
    return 0;
}