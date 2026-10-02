#include<bits/stdc++.h>
using namespace std;

void merger(vector<int>&arr , int low , int mid , int high){
    // you have two sorted halves,now you have to merge them is the logic
    // we use a 2 pointer approach to merge it in linear run time
    vector<int>left_arr,right_arr;
    // usin lamda functions to populate the array
    left_arr = vector<int>(arr.begin()+low , arr.begin()+mid+1);
    right_arr = vector<int>(arr.begin()+mid+1 , arr.begin()+high+1);
    int n1 = mid-low+1;
    int n2 = high-mid;
    int i = 0 , j = 0 , k = low;
    // or instead to be on safer side use left_arr.size() , right_arr.size()
    // now jus ur usual 2 pointer approach
    while(i < n1 && j < n2){
        if(left_arr[i] <= right_arr[j]){
            arr[k++] = left_arr[i++];
        }
        else{
            arr[k++] = right_arr[j++];
        }
    }
    // remaining elements
    while(i < n1){
        arr[k++] = left_arr[i++];
    }
    while(j < n2){
        arr[k++] = right_arr[j++];
    }

}

void merge(vector<int>&arr , int low , int high){
    // base case
    if(high <= low){
        return;
    }
    int mid = (low + high) / 2;

    // left half , right half then merge
    merge(arr , low , mid);
    merge(arr , mid+1 , high);
    // now just run merger function which actually does everything
    merger(arr , low , mid , high);

}

void print_vector(vector<int>&v){
    for(auto &ele : v){
        cout << ele << ' ';
    }
    cout << endl;
}



int main(){
    // recurrence relationship : T(n) = 2.T(n/2) + n
    vector<int>arr = {10,11,13,8,7,5};
    merge(arr , 0 , arr.size()-1);
    print_vector(arr);
    
}