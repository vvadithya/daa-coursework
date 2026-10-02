#include<bits/stdc++.h>
using namespace std;

// tc:O(2**n) , sc:O(n)


int func(int n , vector<int>&values){
    int maxi = 0;
    for(int i = 1 ; i <= n ; i++){
        maxi = max(maxi , values[i] + func(n-i , values));
    }
    return maxi;

}


int main(){
    vector<int>values = {0 , 2 , 4  , 5};
    int n = values.size();
    cout << func(n-1 , values) << endl;
}