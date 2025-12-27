class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If mid points to the target
            if (arr[mid] == target) return true;

            // Edge case
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }

            // If the left half is sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= target && target <= arr[mid]) high = mid - 1; 
                else low = mid + 1;
            } else {
                // Right half is sorted
                if (arr[mid] <= target && target <= arr[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return false;
    }
};