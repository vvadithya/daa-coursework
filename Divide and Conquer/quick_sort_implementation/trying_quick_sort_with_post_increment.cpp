#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int>&v){
    for(auto &ele : v){
        cout << ele << ' ';
    }
    cout << endl;
}

int partition(int low , int high , vector<int>&arr){
    int pivot_element = arr[high];//make ur comparisions with this element
    int i = low;//start of region with elements less than pivot
    for(int j = low ; j < high ; j++){
        if(arr[j] <= pivot_element){
            swap(arr[i++] , arr[j]);// whenever we encounter,we just swap
        }
    }
    swap(arr[i] , arr[high]);//swapping pivot_element and lower end,what this does is
    // all to left of i are less than pivot element and all to right of pivot element are greater
    return i;
}

void qs(int low , int high , vector<int>&arr){
    if(high < low)return;
    // always remember pivot is already in final sorted position
    // so dont call it in left and right region...
    int pivot = partition(low , high , arr); // we pass low,high cause we need to know what range to analyse the pivot in
    qs(low , pivot-1 , arr); // further call it in the region left of pivot
    qs(pivot+1 , high , arr); // further call it in the region right of pivot
}


int main(){
    vector<int>arr = {10,2,-1,0,100,102};
    int n = arr.size();
    qs(0 , n-1 , arr);
    print_vector(arr);
}