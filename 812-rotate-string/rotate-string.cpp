class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        else if(s.length() != goal.length()) return false;

        int n = s.length();
        string original = s;
        int k = 1;
        while(n--){
            s = original;
            
            reverse(s.begin(), s.begin()+k);
            reverse(s.begin()+k, s.end());
            reverse(s.begin(), s.end());
            if(s==goal) return true;
            k++;
        }
        return false;
    }
};