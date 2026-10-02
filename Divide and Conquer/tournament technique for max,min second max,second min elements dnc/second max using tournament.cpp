#include<bits/stdc++.h>
using namespace std;

int func(int low , int high , vector<int>&v , unordered_map<int,vector<int>>&mpp){
    if(high < low){
        return INT_MIN;
    }
    if(low + 1 == high){
        mpp[v[low]].push_back(v[high]);
        mpp[v[high]].push_back(v[low]);
        return max(v[low] , v[high]);
    }
    // case of odd split
    if(low == high){
        return v[low];
    }
    int mid = (low+high)/2;
    int left_half = func(low , mid , v , mpp);
    int right_half = func(mid+1 , high , v , mpp);
    mpp[left_half].push_back(right_half);
    mpp[right_half].push_back(left_half);
    return max(left_half , right_half);
}

void print_vector(vector<int>&v){
    for(auto &ele : v){
        cout << ele << ' ';
    }
    cout << endl;
}


int main(){
    unordered_map<int,vector<int>>mpp;
    vector<int>v = {16,13,12,5,8,9,10,17};
    int maxi =  func(0 , v.size()-1 , v , mpp);
    // vector<int>v2 = mpp[maxi];
    // print_vector(v2);
    cout << *max_element(mpp[maxi].begin() , mpp[maxi].end());
}