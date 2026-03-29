class Solution {
public:
    bool checkStrings(string s1, string s2) {
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) {
                for(int j=i; j<s1.size(); j+=2){
                    if (s1[j] == s2[i]) {
                        swap(s1[i], s1[j]);
                        break;
                    }
                }

                if (s1[i] != s2[i]) return false;
            }
        }

        return true;
    }
};