#include<bits/stdc++.h>
using namespace std;

// at each step we can make two choices to pick or not to pick
// there are n such steps
// since we have to check all possible combinations therefore the 2^n combinations to check
// therefore time complexity is O(2**n) and space complexity is O(n)

int func(int idx , int weight , vector<int>&weights , vector<int>&values){
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
    int no_take = 0 + func(idx - 1 , weight , weights , values);
    int take = INT_MIN;
    if(weight >= weights[idx]){
        take = values[idx] + func(idx - 1 , weight - weights[idx] , weights , values);
    }
    return max(take , no_take);
}

int main(){
    vector<int>weights = {3 , 2 , 5};
    vector<int>values = {30 , 40 , 80};
    int bag_cap = 6;
    cout << func(weights.size()-1 , bag_cap , weights, values);
}