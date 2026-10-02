#include<bits/stdc++.h>
using namespace std;

// this code finds kth smalllest element,here we choose n/2 therefor finds median
// avg time complexity is O(n) but in worst case goes to O(n*n)

int quick_select(vector<int>&arr , int low , int high , int k){
    // base case
    if(low >= high){
        return arr[low];
    }
    // now take pivot element , and almost same quick sort implementation
    int pivot_element = arr[high];
    int i = low - 1;
    for(int j = low ; j < high ; j++){
        if(arr[j] <= pivot_element){
            swap(arr[++i] , arr[j]);
        }
    }
    // i+1 is our pivot
    swap(arr[i+1] , arr[high]);
    int pivot = i+1;
    if(pivot == k){
        return arr[pivot];
    }
    else if(pivot < k){
        // therefore only look in the right half
        return quick_select(arr , pivot+1 , high , k);
    }
    else{
        // look in the left half only
        return quick_select(arr , low , pivot-1 , k);
    }
}

double median(vector<int>&arr){
    int n = arr.size();
    int k = n/2;
    if(n & 1){
        // n is odd
        return quick_select(arr , 0 , n-1 , k);
    }
    else{
        int a = quick_select(arr , 0 , n-1 , k);
        int b = quick_select(arr , 0 , n-1 , k-1);
        double c = (a + b);
        return c / 2.0;
    }

}




int main(){
	vector<int>a = {-1 , 10 , 22 , 100};
    vector<int>b = {-100 , 1 , 100};

    cout << median(a) << endl;
    cout << median(b) << endl;
}
