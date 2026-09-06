class Solution {
public:
    int bs(vector<int>& nums, int start, int end, int target) {
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] > target) end=mid-1;
            else if(nums[mid] < target) start=mid+1;
            else return mid;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = -1;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]) {
                k = i;
                break;
            }
        }

        if(k==-1) return bs(nums, 0, n-1, target);

        int dt = bs(nums, 0, k, target);
        int j = bs(nums, k+1, n-1, target);

        if(dt != -1) return dt;
        if(j != -1) return j;

        return -1;
    }
};