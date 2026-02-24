class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = strs[0];
        int i=1;
        while(i<n){
            string curr=strs[i];
            string temp;
            int k = min(curr.length(), prefix.length());
            for(int j=0; j<k; j++){
                if(prefix[j]==curr[j]) temp+=prefix[j]; 
                else break;
            }
            prefix=temp;
            i++;
        }

        return prefix;
    }
};