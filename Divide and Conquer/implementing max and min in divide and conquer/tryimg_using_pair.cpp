#include<bits/stdc++.h>
using namespace std;


pair<int,int> func(int low , int high , vector<int>&arr){
    // base cases
    if(low == high){
        return {arr[low] , arr[high]};
        // min,max have to be the same twn
    }
    // other base case is when size = 2 , we can reduce no of comparisions to one
    if(low +1 == high){
        if(arr[low] <= arr[high]){
            return {arr[low] , arr[high]};
        }
        return {arr[high] , arr[low]};
    }
    // other base case is low > high
    if(low > high){
        // notice the order of INT_MAX in the place of low and INT_MIN in the place of high
        return {INT_MAX , INT_MIN};
    }
    // now check left half , right half and recombine
    int mid = (low+high)/2;
    pair<int,int>left_half = func(low , mid , arr);
    pair<int,int>right_half = func(mid+1 , high , arr);
    // now compare and return,2 comparisions
    int maxi = max(right_half.second , left_half.second);
    int mini = min(right_half.first , left_half.first);
    return {mini , maxi};
}

int main(){
    vector<int>arr = {-1 , 100 , 2032 , 199 , 0};
    int n = arr.size();
    pair<int,int>ans = func(0 , n-1 , arr);
    cout << "MINIMUM : " << ans.first << "\nMAXIMUM : " << ans.second << "\n";
}