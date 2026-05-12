class Solution {
public:
    bool isPossible(vector<vector<int>> tasks, int mid, int n){
        for(int i=0; i<n; i++){
            if(tasks[i][1]>mid) {
                return false;
            } else {
                mid -= tasks[i][0];
            }
            
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int l=0, r= (int) 1e9;
        int ans;

        auto lambda = [](auto &task1, auto& task2) {
            int diff1 = task1[1]-task1[0];
            int diff2 = task2[1]-task2[0];

            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lambda);

        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPossible(tasks, mid, n)){
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return ans;
    }
};