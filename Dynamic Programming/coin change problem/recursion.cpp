#include<bits/stdc++.h>
using namespace std;

int ways_to_make_sum(int i , int target , const vector<int>&coins){
    // base case
    if(target == 0){
        return 1;
    }
    if(i < 0 || target < 0){return 0;}
    // either include coin and stay here or dont include and go ahead
    int include = ways_to_make_sum(i , target-coins[i] , coins);
    int dont_include = ways_to_make_sum(i-1,target , coins);
    return include + dont_include;
}

// int minimum_coins_to_target(int i , int target , const vector<int>&coins , int coins_taken){
//     if(target == 0){
//         return coins_taken;
//     }
//     if(i < 0 || target < 0){
//         return 1e9;
//     }
    
//     int include = minimum_coins_to_target(i , target-coins[i] , coins , coins_taken+1);
//     int dont_include = minimum_coins_to_target(i-1,target,coins,coins_taken);
//     return min(include,dont_include);
// }

int min_coins_to_target(int i,int target,const vector<int>&coins){
    if(target == 0){return 0;}
    if(i<0||target<0){return 1e9;}
    int incl = 1 + min_coins_to_target(i,target-coins[i],coins) , excl = min_coins_to_target(i-1,target,coins);
    return min(incl,excl);
}

int main(){
    vector<int>coins = {1 , 3 , 7 , 10};
    int target = 57 , n = coins.size();
    cout << ways_to_make_sum(n-1 , target , coins) << endl;
    // cout << minimum_coins_to_target(n-1,target,coins,0) << endl;
    cout << min_coins_to_target(n-1,target,coins) << endl;

}