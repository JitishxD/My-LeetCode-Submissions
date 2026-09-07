class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        int dt = 0;
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        while(start<=end){
            int mid = start + (end-start)/2;
            if(mid<n-1 && mid>0) {
                if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]) {
                    dt = mid;
                    break;
                }
                
                if(nums[mid]==nums[mid-1]) {
                    // in pair we're at second pos
                    if((mid)%2==0){
                        // we're at single element's right side
                        end = mid-1;
                    } else start = mid+1;
                } else if (nums[mid]==nums[mid+1]) {
                    // in pair we're at first pos
                    if((mid)%2!=0){
                        // we're at single element's right side
                        end = mid-1;
                    } else start = mid+1;
                }
            }
        }

        return nums[dt];
    }
};