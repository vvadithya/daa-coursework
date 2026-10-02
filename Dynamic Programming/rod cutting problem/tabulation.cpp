#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>values = {0 , 2 , 4  , 5};
    int n = values.size();
    vector<int>dp(n , -1);
    dp[0] = 0;
    for(int i = 1 ; i < n ; i++){
        int maxi = 0;
        for(int j = 0 ; j <= i ; j++){
            maxi = max(maxi , values[j] + dp[i-j]);
        }   
        dp[i] = maxi;
    }
    cout << dp[n-1] <<"\n";
}