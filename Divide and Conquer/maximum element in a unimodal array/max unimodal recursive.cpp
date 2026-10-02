#include<bits/stdc++.h>
using namespace std;

int unimodal_recursive(vector<int>&arr , int low , int high){
    // base case
    if(high <= low){
        return arr[low];
    }
    int mid = (low + high) / 2;
    if(arr[mid] < arr[mid+1]){
        // slope is upwards
        // therefore the maxima is towards the right
        return unimodal_recursive(arr , mid+1 , high);
    }
    else{
        // slope is either downwards or equal
        // therefore the maxima is towards teh left
        return unimodal_recursive(arr , low , mid);
    }

}

using namespace std;


int main(){
    // a unimodal array keeps increasing upto a point and then starts decreasing
    // casual brute approach is O(n)
    // using this binary search-ish logic we can bring it down to O(log2N)
    // if the arr is empty,note that youll get a seg fault
	vector<int>arr = {10 , 20 , 30 , 40 , 90 , 110 , 109 , 108};
    cout << unimodal_recursive(arr , 0 , arr.size()-1) << endl;

}
