class Solution {
public:
    int rotatedDigits(int n) {
        set<int> invalid = {3,4,7};
        set<int> changing = {2,5,6,9};
        vector<int> ans;
        bool change = false, valid = true;
        int count=0;
        for(int i=1; i<=n; i++){
            int temp = i;
            while(temp!=0){
                int digit = temp%10;
                if (invalid.find(digit) != invalid.end()) {
                    valid = false;
                    break;
                }

                if (changing.find(digit) != changing.end()) {
                    change = true;
                }
                temp /= 10;
            }
            if(valid && change){
                count++;
            }
            change = false, valid = true;
        }
        
        return count;
    }
};