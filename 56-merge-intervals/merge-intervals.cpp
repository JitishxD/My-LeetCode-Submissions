class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort on the basis of start value.
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& curr = intervals[i];
            vector<int>& last = ans.back();

            if (curr[0] <= last[1]) {
                last[1] = max(last[1], curr[1]);
            } else {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};