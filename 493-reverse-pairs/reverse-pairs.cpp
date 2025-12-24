class Solution {
public:
    int merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;
        int count=0;
        while(right<=high && left<=mid) {
            if(arr[left]>(long long)2*arr[right] ){
                count = count+(mid-left+1);
                right++;
            } else {
                left++;
            }
        }
        left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else {
                temp.push_back(arr[right++]);
            }
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];

        return count;
    }

    int mergeSortFunc(vector<int>& nums, int low, int high){
        int count = 0;
        if (low>=high) return count;
        int mid = (low+high)/2;
        count+=mergeSortFunc(nums, low, mid);
        count+=mergeSortFunc(nums, mid+1, high);
        count+=merge(nums, low, mid, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1;
        
        return mergeSortFunc(nums, low, high);
    }
};