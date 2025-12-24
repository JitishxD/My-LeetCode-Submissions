class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0, count2=0;
        int ele1=0, ele2=0;
        vector<int> ans;

        for(int n: nums){
            if (count1 == 0 && ele2 != n) {
                count1 = 1;
                ele1 = n; 
            }
            else if (count2 == 0 && ele1 != n) {
                count2 = 1;
                ele2 = n; 
            } 
            else if (n == ele1) {
                count1++;
            } 
            else if (n == ele2) {
                count2++; 
            } 
            else {
                count1--; 
                count2--;
            }
        }

        count1=count2=0;
        for(int n: nums){
            if(n==ele1) count1++;
            if(n==ele2) count2++;
        }

        int minAppearance = n/3+1;
        if(count1>=minAppearance){
            ans.push_back(ele1);
        }
        if(count2>=minAppearance && ele1!=ele2){
            ans.push_back(ele2);
        }

        return ans;
    }
};