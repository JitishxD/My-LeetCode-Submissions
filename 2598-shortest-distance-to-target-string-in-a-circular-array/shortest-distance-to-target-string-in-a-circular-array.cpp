class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int m = target.length();
        int minLength = INT_MAX;
        for(int i=0; i<n; i++){
            if(words[(startIndex+i) % n] == target){ 
                minLength = min(minLength, i);
            }

            if(words[(startIndex-i+n) % n] == target) { 
                minLength = min(minLength, i);
            }
        }

        return minLength==INT_MAX?-1:minLength;
    }
};