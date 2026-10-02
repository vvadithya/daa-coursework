#include<bits/stdc++.h>
using namespace std;

// some changes
// only track when low == high,ur left_part , right_part handles it well
// also only the winner should track the loser,earlier version even loser was tracking winner
// un-necessary waste of space
// if u wanna improve optimsiation even more use const vector<int>&v

int func(int low , int high , const vector<int>&v , unordered_map<int,vector<int>>&mpp){
    if(high < low){
        return INT_MIN;
    }
    if(low == high){
        return v[low];
    }
    int mid = (low+high)/2;
    int left_half = func(low , mid , v , mpp);
    int right_half = func(mid+1 , high , v , mpp);
    int winner = max(left_half , right_half);
    if(winner == left_half){
        mpp[winner].push_back(right_half);
    }
    else{
        mpp[winner].push_back(left_half);
    }
    return winner;
}



int main(){
    unordered_map<int,vector<int>>mpp;
    vector<int>v = {16,13,12,5,8,9,10,17};
    int maxi =  func(0 , v.size()-1 , v , mpp);
    cout << *max_element(mpp[maxi].begin() , mpp[maxi].end()) << "\n";
}