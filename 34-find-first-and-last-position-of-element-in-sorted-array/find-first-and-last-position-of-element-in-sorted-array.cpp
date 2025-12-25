class Solution {
public:
    int binarySearch(const vector<int>& nums, int low, int high, int target, bool searchFirst){
        int ans=-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if(searchFirst) high = mid - 1;
                else low = mid + 1;
            } else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1; 
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = binarySearch(nums, 0, n-1, target, true);
        if (first == -1) return {-1, -1};
        int second = binarySearch(nums, 0, n-1, target, false);

        return {first, second};        
    }
};