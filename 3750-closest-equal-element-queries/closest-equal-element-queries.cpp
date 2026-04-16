class Solution {
public:
    int binarySearch(vector<int>& arr, int target){
        int i=0, j=arr.size()-1;
        while(i <= j){
            int mid = i+(j-i)/2;

            if(arr[mid] == target) return mid;
            else if(arr[mid] < target) i = mid+1;
            else j = mid-1;
        }
        return -1;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m = queries.size();
        vector<int> ans(m, -1);
        unordered_map<int, vector<int>> indices;
        for(int i=0; i<n; i++){
            indices[nums[i]].push_back(i);
        }

        for(int i=0; i<m; i++){
            int q_idx = queries[i];
            int val = nums[q_idx];
            int res = INT_MAX;

            vector<int>& curr_idx = indices[val];
            int sz = curr_idx.size();

            if(sz == 1){
                ans[i] = -1;
                continue;
            }

            int k = binarySearch(curr_idx, q_idx);

            // The next k at left side (circularly)
            int left = curr_idx[((k-1)+sz)%sz];
            int d1 = abs(left-q_idx);
            res = min({res, d1, n-d1});

            // the next k at right side (circularly)
            int right = curr_idx[(k+1)%sz];
            int d2 = abs(right-q_idx);
            res = min({res, d2, n-d2});

            ans[i] = res; 
        }
    return ans;
    }
};