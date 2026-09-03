class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> dt = nums1;
        int j = *min_element(dt.begin(), dt.end());
        // can we make all odd? case
        // subtrating the smallest number each time we can change every other number parity
        // like all even -> all odd , if some already odd we can take them directly
        // smallest uss condition ki wajah warna unka result >= 1 nhi hoga
        if(j%2==1) return true; 

        for(int n: dt){
            if(n%2==1) return false;
        }

        // already all even case
        return true;
    }
};