#include<bits/stdc++.h>
using namespace std;

// note were accounting for the no of elements compared
// not the no of operations,because index comparing is much more insignificant
// imagine instead of the vectors having numbers,we had some other form of data to compare
// this technique is still useful there also


void func(int left , int right , vector<int>&arr , int&mini , int&maxi , int &count_operations){
    // base cases
    // case1: both end up on same index,0 comparisions
    if(left == right){
        mini = arr[left];
        maxi = arr[left];
        count_operations += 0;
        return;
    }
    // case2:right is just ahead of left by 1,ie consecutive elements,2 elements only
    if(left == right - 1){
        // u can get min and max with one comparision only
        if(arr[left] < arr[right]){
            mini = arr[left];
            maxi = arr[right];
        }
        else{
            mini = arr[right];
            maxi = arr[left];
        }
        count_operations += 1;
        return;
    }
    // now this is similar to post order why?
    // because in this divide and conquer,we break into left_part and right_part
    // we get the answer from them
    // and then process our current level
    
    // now since this is a void function,ill need to store the info
    int left_min , left_max , right_min , right_max;
    // splitting to two halves using mid
    int mid = (left + right) / 2;
    // call the functions
    func(left , mid , arr , left_min , left_max , count_operations);
    func(mid+1 , right , arr , right_min , right_max , count_operations);
    // now do the nodal level,the two halves have given you left_min and right_min AND left_max AND right_max
    mini = min(left_min , right_min);
    maxi = max(left_max , right_max);
    count_operations += 2;

}

int main(){
    vector<int>v = {10,20,30,40,50,60};
    int mini , maxi , count_operations = 0;
    func(0 , v.size()-1 , v , mini , maxi , count_operations);
    cout << "MINIMUM : " << mini << endl;
    cout << "MAXIMUM : " << maxi << endl;
    cout << "ELEMENT COMPARISIONS REQUIRED : " << count_operations << endl;
    cout << "THEORETICAL OPERATIONS REQUIRED IS 1.5*N - 2 ie: " <<  1.5*v.size()-2 << endl;
}