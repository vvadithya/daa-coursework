#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr , int low , int high , mt19937& rng){
    uniform_int_distribution<int> dist(low, high);
    int random_idx = dist(rng);
    // now rest is very similar
    swap(arr[high] , arr[random_idx]);
    // and now everything is the same as the quicksort partition function
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

void quicksort(vector<int>&arr , int low , int high , mt19937& rng){
    if(high <= low){
        return;
    }
    int pivot_idx = partition(arr , low , high , rng);
    quicksort(arr , low , pivot_idx , rng);
    quicksort(arr , pivot_idx+1 , high , rng);
}

void print_vector(vector<int>&v){
    for(auto &ele : v){
        cout << ele << ' ';
    }
    cout << endl;
}


int main(){
    // initialising random number generation
    mt19937 rng(random_device{}());
    vector<int>arr = {10 , 20 , -10 , 0 , 40, 8 , -11};
    quicksort(arr , 0 , arr.size()-1 , rng);
    print_vector(arr);
	return 0;
}
