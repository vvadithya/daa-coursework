#include<bits/stdc++.h>
using namespace std;

// tc : O(n*n) , sc : o(N) + O(n)

int func(int n , vector<int>&values , vector<int>&memo){
    int maxi = 0;
    if(memo[n] != -1){
        return memo[n];
    }
    for(int i = 1 ; i <= n ; i++){
        maxi = max(maxi , values[i] + func(n-i , values , memo));
    }
    return memo[n] = maxi;

}


int main(){
    vector<int>values = {0 , 2 , 4  , 5};
    int n = values.size();
    vector<int>memo(n , -1);
    cout << func(n-1 , values , memo) << endl;
}