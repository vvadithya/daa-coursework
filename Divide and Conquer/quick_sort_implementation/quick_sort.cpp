#include<bits/stdc++.h>
using namespace std;

// #include <vector>
// using namespace std;

// void quickSort(vector<int>& arr, int low, int high) {
//     if (low >= high) return;
    
//     // Partition: place pivot at correct position
//     int pivot = arr[high];  // Choose last element as pivot
//     int i = low - 1;        // Index for smaller elements
    
//     for (int j = low; j < high; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);  // Place pivot at correct position
//     int pivotIndex = i + 1;
    
//     // Recursively sort left and right parts
//     quickSort(arr, low, pivotIndex - 1);
//     quickSort(arr, pivotIndex + 1, high);
// }

int partition(vector<int>&arr , int low , int high){
    int pivot_element = arr[high];
    int i = low - 1;
    for(int j = low ; j < high ; j++){
        if(arr[j] <= pivot_element){
            swap(arr[++i] , arr[j]);
        }
    }
    swap(arr[i+1] , arr[high]);
    return i;
}


void quicksort(vector<int>&arr , int low , int high){
    if(low >= high){
        return;
    }
    int pivot_idx = partition(arr , low , high);
    quicksort(arr , low , pivot_idx);
    quicksort(arr , pivot_idx+1 , high);
}

void print_vector(vector<int>&v){
    for(auto &ele : v){
        cout << ele << ' ';
    }
    cout << endl;
}

int main(){
    vector<int>arr = {10,2,-1,0,100,102};
    quicksort(arr , 0 , arr.size()-1);
    print_vector(arr);

}