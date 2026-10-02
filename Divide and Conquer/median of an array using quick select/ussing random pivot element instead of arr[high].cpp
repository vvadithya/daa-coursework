#include <random>

class Solution {
public:
    int quick_select(vector<int>& arr, int low, int high, int k, mt19937& rng) {
        if (low >= high) {
            return arr[low];
        }

        int random_idx = uniform_int_distribution<int>(low, high)(rng);

        swap(arr[random_idx], arr[high]);

        int pivot_element = arr[high];

        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot_element) {
                swap(arr[++i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        int pivot = i + 1;

        if (pivot == k) {
            return arr[pivot];
        }

        if (pivot < k) {
            return quick_select(arr, pivot + 1, high, k, rng);
        }

        return quick_select(arr, low, pivot - 1, k, rng);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

        return quick_select(nums, 0, n - 1, n - k, rng);
    }
};

// note i had to < instead of <= because of too many duplicate values