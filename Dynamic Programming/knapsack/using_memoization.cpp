#include<bits/stdc++.h>
using namespace std;

// time complexity is O(bag_cap * n)
// space complexity is also O(bag_cap * n)

int func(int idx , int weight , vector<int>&weights , vector<int>&values , vector<vector<int>>&memo){
    if(idx < 0){
        return 0;
    }
    if(idx == 0){
        // just pick at this case,no point analysing the no pick case since its obvuiously gonna be worse
        if(weights[idx] <= weight){
            return values[idx];
        }
        return 0;
    }
    if(memo[idx][weight] != -1){
        return memo[idx][weight];
    }
    int no_take = 0 + func(idx - 1 , weight , weights , values , memo);
    int take = INT_MIN;
    if(weight >= weights[idx]){
        take = values[idx] + func(idx - 1 , weight - weights[idx] , weights , values , memo);
    }
    return memo[idx][weight] = max(take , no_take);
}

int main(){
    vector<int>weights = {3 , 2 , 5};
    vector<int>values = {30 , 40 , 80};
    int n = weights.size();
    int bag_cap = 6;
    vector<vector<int>>memo(n , vector<int>(bag_cap + 1 , -1));
    cout << func(n-1 , bag_cap , weights, values , memo);
}

