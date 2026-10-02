#include<bits/stdc++.h>
using namespace std;

int func(int low , int high , vector<int>&v){
    if(high < low){
        return INT_MAX;
    }
    if(low + 1 == high){
        return min(v[low] , v[high]);
    }
    // case of odd split
    if(low == high){
        return v[low];
    }
    int mid = (low+high)/2;
    int left_half = func(low , mid , v);
    int right_half = func(mid+1 , high , v);
    return min(left_half , right_half);
}


int main(){
    vector<int>v = {15,13,12,5,8,9,10,17};
    cout << func(0 , v.size()-1 , v) << "\n";

    v = {-10 , -8 , -1};
    cout << func(0 , v.size()-1 , v) << "\n";

    //     vector<int>v = {15,13,12,5,8,9,10,17};
    // cout << func(0 , v.size()-1 , v) << "\n";
}