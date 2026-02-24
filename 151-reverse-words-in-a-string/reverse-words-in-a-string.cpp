class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i=0, j=0;

        // remove extra spaces
        while(j<n){
            while(j<n && s[j]==' ') j++;
            while(j<n && s[j]!=' ') s[i++] = s[j++];
            while(j<n && s[j]==' ') j++;
            if (j < n) s[i++] = ' ';   
        }

        // resize the string with new correct length i 
        s.resize(i);

        reverse(s.begin(), s.end());

        // reverse each word
        int start=0;
        n=s.length();
        for(int end=0; end<=n; end++){
            if(end==n || s[end]==' '){
                reverse(s.begin()+ start, s.begin()+end);
                start = end+1;
            }
        }
        return s;
    }
};