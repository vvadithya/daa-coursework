#include<bits/stdc++.h>
using namespace std;

// time complexity is O(2^(min(n,m))) to O(2^(n+m))
// space complexity is the recursion stack therefore O(n+m)

int func(int idx1 , int idx2 , string &s1 , string &s2){
    //if idx is negative means we have reached the end of the string

    if(idx1 < 0 || idx2 < 0){
        return 0;
    }
    // check if math
    bool is_match = (s1[idx1] == s2[idx2]);
    if(is_match){
        return 1 + func(idx1-1 , idx2-1 , s1 , s2);
    }
    else{
        return 0 + max(func(idx1-1 , idx2 , s1 ,s2) , func(idx1 , idx2-1 , s1 , s2));
    }
}

int main(){
    string s1 = "abcde" , s2 = "bcdae";
    cout << func(s1.size()-1 , s2.size()-1 , s1 , s2);
}