#include<bits/stdc++.h>
using namespace std;

int bin_search(int target , vector<int>&arr , int low , int high){
    if(low > high){
        return -1;
    }

    // tc: O(log2n)
    int mid = (low+high)/2;
    if(arr[mid] < target){
        return bin_search(target , arr , mid+1 , high);
    }
    else if(arr[mid] > target){
        return bin_search(target , arr , low , mid-1);
    }
    else{
        return mid;
    }

}


int main(){
    vector<int>arr = {10,20,30,40,50};
    cout << bin_search(15 , arr , 0 , arr.size()-1) << endl;
    cout << bin_search(30 , arr , 0 , arr.size()-1) << endl;
}

