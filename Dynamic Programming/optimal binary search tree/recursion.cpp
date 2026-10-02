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


int cost(int i , int j , const vector<int>&freq){
    // lets say our root node is r
    // so now left subtree is going to be keys from k1 to kr-1
    // right subtree is going to be keys from kr+1 to kn
    // so check for all possible rs and return minimum
    
    // also no matter root,we have to incur a cost
    // note that on picking a node,every element will go down by 1 level
    // so just sum up from i to j

    // base cases
    if(i > j){
        // not a valid rnage,therefore no nodes selected,no cost
        return 0;
    }
    int level_cost = 0;
    for(int x = i ; x <= j ; x++){
        level_cost += freq[x];
    }
    int mini_case_of_root = INT_MAX;
    for(int r = i ; r <= j ; r++){
        mini_case_of_root = min(mini_case_of_root , cost(i , r-1 , freq) + cost(r+1 , j , freq));
    }
    return mini_case_of_root + level_cost;
}

int main(){
    vector<int> freq = {4, 2, 6, 3};
    cout << cost(0 , freq.size()-1 , freq);

}