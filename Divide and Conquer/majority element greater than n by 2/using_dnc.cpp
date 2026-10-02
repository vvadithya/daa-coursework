#include<bits/stdc++.h>
using namespace std;

// basically majority of n we divide to two subproblems left and right subhalf
// and then we combine the results we get from the both of them
// in case left and right half give diff output,just recount them using count() function
// also were trying not to use space (ignoring recursive stack space)


int count(int low , int high , int key , vector<int>&arr){
    int cnt = 0;
    for(int i = low ; i <= high ; i++){
        if(arr[i] == key){
            cnt++;
        }
    }
    return cnt;
}

// assume -1 is some kind of flag and wont ever come in inputs

int func(int low , int high , vector<int>&arr){
    // base case
    if(low == high){
        return arr[low];
    }
    int mid = (low+high)/2;
    int left_half = func(low , mid , arr);
    int right_half = func(mid+1 , high , arr);
    if(left_half == right_half){
        return left_half;
    }
    if(count(low , high , left_half , arr) >= count(low , high , right_half , arr)){
        return left_half;
    }
    else{
        return right_half;
    }
}


int main(){
    // u shld always verify again btw,cz if {1,2,3,4} no one is majority and smn will be returned
    vector<int>v = {10 , 10 , 10 ,30 , 40 , 10 , 10 ,50};
    int n = v.size() ,  ans = func(0 , n -1 , v);
    if(count(0 , n - 1 , ans , v) > n / 2){
        cout << ans << " IS MAJORITY ELEMENT";
    }
    else{
        cout << " NO MAJORITY ELEMENT";
    }
     
}