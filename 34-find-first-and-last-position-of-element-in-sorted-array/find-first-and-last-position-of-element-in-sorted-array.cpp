class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start=0, end=n-1;
        int dt=n, j=n;

        //lower_bound
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]>=target) {
                dt = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
            
        }

        //upper_bound
        start=0, end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]>target) {
                j = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }   
        }

        if(dt == nums.size() || nums[dt] != target) return {-1, -1};

        return {dt, j-1};
    }
};