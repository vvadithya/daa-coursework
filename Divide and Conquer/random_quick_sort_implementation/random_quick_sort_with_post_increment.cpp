#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int>&v){
    for(auto &ele : v){
        cout << ele << ' ';
    }
    cout << endl;
}


int partition(int low , int high , vector<int>&arr , mt19937 &mt){
    uniform_int_distribution<int> distri(low , high);
    int random_number = distri(mt);
    swap(arr[random_number] , arr[high]);    
    int pivot_element = arr[high];
    int i = low; // i is our pivot
    for(int j = low ; j < high ; j++){
        if(arr[j] <= pivot_element){
            swap(arr[i++] , arr[j]);
        }
    }
    swap(arr[i] , arr[high]);
    return i;
}

void qs(int low , int high , vector<int>&arr ,  mt19937 &mt){
    if(low > high)return;
    // choose pivot element
    int pivot = partition(low , high , arr , mt);
    // pivot is already in the right sorted position
    qs(low , pivot-1 , arr , mt);
    qs(pivot+1 , high , arr , mt);
}

int main(){
    vector<int>arr = {10,2,-1,0,100,102};
    mt19937 mt(time(nullptr));
    int n = arr.size();
    qs(0 , n-1 , arr , mt);
    print_vector(arr);
}