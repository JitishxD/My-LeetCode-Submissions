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
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m, -1);
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i<n; i++) {
            pos[nums[i]].push_back(i);
        }

        for(int i=0; i<m; i++){
            int q_idx = queries[i];
            int val = nums[q_idx];

            vector<int>& indices = pos[val];
            int sz = indices.size();

            if (sz == 1) {
                ans[i] = -1;
                continue;
            }

            int k = binarySearch(indices, q_idx);
            
            // if k=0 then k-1=-1 so we add sz
            int left_idx = indices[(k-1+sz) % sz];
            int right_idx = indices[(k+1) % sz];
            
            int d1 = abs(left_idx - q_idx);
            int d2 = abs(right_idx - q_idx);

            d1 = min(d1, n-d1);
            d2 = min(d2, n-d2);

            ans[i]= min(d1, d2);


        }
        return ans;
    }
};