class Solution {
public:
    int binarySearch(vector<int>& arr, int low, int high, int key) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    int minElem(vector<int>& arr, int low, int high) {
        while (low <= high) {
            // array is already sorted
            if (arr[low] <= arr[high]) return low;

            int mid = low + (high - low) / 2;
            // right half of array is not sorted
            if (arr[mid] > arr[high]) low = mid + 1;
            // right half of array is sorted
            else high = mid;
        }
        return low;
    }

    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int pivot = minElem(arr, 0, n - 1);

        if (arr[pivot] == key) return pivot;

        // array is sorted.
        if (pivot == 0) return binarySearch(arr, 0, n - 1, key);

        if (arr[0] <= key) return binarySearch(arr, 0, pivot - 1, key);

        return binarySearch(arr, pivot + 1, n - 1, key);
    }
};