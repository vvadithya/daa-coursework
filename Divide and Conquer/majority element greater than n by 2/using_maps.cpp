#include<bits/stdc++.h>
using namespace std;

int majority_map(vector<int>&v , unordered_map<int,int>&mpp){
    for(int num : v){
        mpp[num]++;
    }
    int n = v.size();
    for(auto &p : mpp){
        if(p.second > n/2){
            return p.first;
        }
    }
    // if not found
    return -1;
}


int main(){
    vector<int>v = {10 , 10 , 10 ,30 , 40 , 10 , 10 ,50};
    unordered_map<int,int>mpp;
    cout << majority_map(v , mpp) << " is majority element";
}

