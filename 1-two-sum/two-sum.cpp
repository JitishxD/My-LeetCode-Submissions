class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> um;
        int n = arr.size();
        int count =0;

        for(int i=0; i<n; i++){
            if(um.find(target-arr[i]) != um.end()) 
                return {um[target-arr[i]], i};
            um[arr[i]] = i;
        }
        return {};
    }
};