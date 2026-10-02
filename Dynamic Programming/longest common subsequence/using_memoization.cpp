#include<bits/stdc++.h>
using namespace std;


// after using memoization,it is now O(n1.n2) time complexity and O(n1.n2) space complexity
// aux stack space is O(n1 + n2)

int func(int idx1 , int idx2 , string &s1 , string &s2 , vector<vector<int>>&memo){
    //if idx is negative means we have reached the end of the string

    if(idx1 < 0 || idx2 < 0){
        return 0;
    }
    if(memo[idx1][idx2] !=-1){
        return memo[idx1][idx2];
    }
    // check if math
    bool is_match = (s1[idx1] == s2[idx2]);
    if(is_match){
        return memo[idx1][idx2] = 1 + func(idx1-1 , idx2-1 , s1 , s2 , memo);
    }
    else{
        return memo[idx1][idx2] = 0 + max(func(idx1-1 , idx2 , s1 ,s2 , memo) , func(idx1 , idx2-1 , s1 , s2 , memo));
    }
}

int main(){
    string s1 = "abcde" , s2 = "bcda";
    int n1 = s1.size() , n2 = s2.size();
    vector<vector<int>>memo(n1 , vector<int>(n2 , -1));
    cout << func(n1-1 , n2-1 , s1 , s2 , memo);
}