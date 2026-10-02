class Solution {
public:
    // returns k smallest element
    int quick_select(vector<int>&arr , int low , int high , int k){
        // base case
        if(low >= high){
            return arr[low];
        }
        int pivot_element = arr[high];
        int i = low - 1;
        for(int j = low ; j < high ; j++){
            if(arr[j] <= pivot_element){
                swap(arr[++i] , arr[j]);
            }
        }
        swap(arr[i + 1] , arr[high]);
        int pivot = i + 1;
        if(pivot == k){
            return arr[pivot];
        }
        if(pivot < k){
            // look in right side
            return quick_select(arr , pivot+1 , high , k);
        }
        else{
            // look in left side
            return quick_select(arr , low , pivot-1 , k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // (kth largest is n-kth smallest
        return quick_select(nums , 0 , n-1 , n-k);
    }
};