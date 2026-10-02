#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr){
    // o(n*n) approach
    // to be precise O(n(n+1)/2)
    int maxi = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        int sum = 0;
        for(int j = i ; j < arr.size() ; j++){
            sum += arr[j];
            maxi = max(maxi , sum); //check everytime cause negative decrease sum also
        }
    }
    return maxi;
}

// works for all negative aswell
int kadane(vector<int>&arr){
    // o(n) approach
    int sum = 0 , maxi = INT_MIN;
    for(int num : arr){
        if(sum < 0){
            sum = 0;//ie we start restarting our count cause we can ditch wahtever negative count
        }
        sum += num;
        maxi = max(maxi , sum);
    }
    return maxi;
}

int dnc(vector<int>&arr){
    return 0;
}

int main(){
    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "BRUTE APPROACH: " << brute(arr) << endl;
    cout << "KADANE APPROACH: " << kadane(arr) << endl;
    cout << "DIVIDE AND CONQUER APPROACH: " << dnc(arr) << endl;

}