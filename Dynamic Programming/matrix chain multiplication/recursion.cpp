#include<bits/stdc++.h>
using namespace std;

// func(i,j) - minimum cost to multiply matrixes from 1 to n
int func(int i , int j , const vector<int>&p){
    // base case
    if(i == j){return 0;}
    int mini = INT_MAX;
    for(int k = i ; k < j;k++){
        // placing bracket at k
        mini = min(mini , func(i,k,p) + func(k+1,j,p) + p[i-1]*p[k]*p[j]);
    }
    return mini;
}

int main(){
    vector<int>p = {10,20,30,40,30};int n = p.size();
    cout << func(1,n-1,p) << "\n";
}