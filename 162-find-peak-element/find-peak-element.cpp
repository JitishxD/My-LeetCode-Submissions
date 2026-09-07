class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int dt=0;
        int start=0, end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(mid<n-1 && mid>0) {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) {
                    dt = mid;
                    break;
                }
            }

            if(nums[mid]>nums[mid-1]) start=mid+1;
            else end = mid;

        }


        return dt;
    }
};