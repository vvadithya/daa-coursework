#include<bits/stdc++.h>
using namespace std;

int cross(vector<int>&arr , int left , int right , int mid){
    // calculate left_sum_max including mid
    // calculate right_sum_max 
    // add them up
    int sum = 0 , left_sum_max = INT_MIN , right_sum_max = INT_MIN;
    for(int i = mid ; i >= left ; i--){
        sum += arr[i];
        left_sum_max = max(left_sum_max , sum);
    }
    // dont include mid again for right_sum_max calculation
    // weve alr included it for our left_sum_calculation
    sum = 0;
    for(int i = mid + 1 ; i <= right ; i++){
        sum += arr[i];
        right_sum_max = max(sum , right_sum_max);
    } 
    return left_sum_max + right_sum_max;
    
}
// recurrence relationship is: T(n) = T(n/2) + T(n/2) + O(n) 
// because this cross thingy takes n elements to scan
// on solving the recurrence relationship u will get nlog2n
int dnc(vector<int>&arr , int left , int right){
    // 3 cases
    // completely in left , completely in right , passes thru middle element
    
    // base case
    if(left == right){
        return arr[left]; // rturn the value itself
    }
    int mid = (left+right)/2;

    // now 3 cases
    int left_part = dnc(arr , left , mid);
    int right_part = dnc(arr , mid+1 , right);
    int cross_part = cross(arr , left , right , mid);
    return max({left_part , right_part , cross_part});
}


int main(){
    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,-100};
    cout << "MAXIMUM SUBARRAY SUM USING DNC IS: " << dnc(arr , 0 , arr.size()-1) << endl;
}