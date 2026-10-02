#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int i , int j , string &s1 , string &s2 , vector<vector<int>>&memo){
        // if i is empty,delete all from other string
        // if j is empty,delete all from otehr string

        if(i < 0){return j+1;}
        if(j < 0){return i+1;}
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(s1[i] == s2[j]){
            return memo[i][j] = func(i-1 , j-1 , s1 ,s2 , memo);
        }
        else{
            int del = 1 + func(i-1 , j , s1 , s2 ,memo);
            int rep = 1 + func(i-1 , j-1 , s1 , s2,memo);
            int ins = 1 + func(i , j-1 , s1 ,s2,memo);
            return memo[i][j] = min(ins , min(del , rep));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector<int>>memo(n , vector<int>(m , -1));
        return func(n-1 , m-1 , word1 , word2 , memo);
    }
};

int main(){
    Solution sol = Solution();
    cout<<sol.minDistance("horse","ros") << "\n";
    cout<<sol.minDistance("intention" , "execution");
}