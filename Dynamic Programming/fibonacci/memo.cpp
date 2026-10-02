#include<bits/stdc++.h>
using namespace std;


int func(int n , vector<int>&memo){
    // base cases
    if(n == 0){return 0;}
    if(n == 1){return 1;}
    // memo condition
    if(memo[n] != -1){return memo[n];}
    return memo[n] = func(n-1 , memo) + func(n-2 , memo);
}


int main(){
    int n = 9;
    vector<int>memo(n+1 , -1);
    cout << func(n , memo) << "\n";
}