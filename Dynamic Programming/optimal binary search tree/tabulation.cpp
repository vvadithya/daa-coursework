#include<bits/stdc++.h>
using namespace std;

// understand the problem
// u have some sorted keys : [1 , 3 , 5, ,6 , 7 ,10]
// u have their search frequencies as well [x1 , x2 , x3 ....]
// so basically everytime u search some cost is there,which is equal to level
// so if if i query xi times,for that particular node the cost is x1.level(xi)
// total cost is sum of all of these
// observe that the acc values of sorted keys is irrelevant,but the fact that its sorted is important
// allows us to make recurrence rlsp
// well be using two state variables,to find the cost from range i to j


int main(){
    // assume keys are: {k1,k2.....kn}
    vector<int> freq = {4, 2, 6, 3};
    int n = freq.size() , sum = 0;
    vector<int>prefix_sum = {0};
    vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
    for(int num : freq){
        sum += num;
        prefix_sum.push_back(sum);
    }

    // base cases
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j < i ; j++){
            dp[i][j] = 0;
        }
    }

    // now general dp
    for(int len = 1 ; len <= n ;len++)
        {
        for(int i = 0 ; i <= n - len ; i++){
                int j = i + len -1;
                int level_cost = prefix_sum[j+1] - prefix_sum[i];
                int mini = INT_MAX;
                for(int r = i ; r <= j ; r++){
                    int val = 0;
                    // dp[i][r-1] + dp[r+1][j]
                    if(r + 1 <= j){
                        val += dp[r+1][j];
                    }
                    if(r - 1 >= i){
                        val += dp[i][r-1];
                    }
                    mini = min(mini , val);
                }
                dp[i][j] = mini + level_cost; 
            }
    }
    cout << dp[0][n-1] << "\n";
        }
    

