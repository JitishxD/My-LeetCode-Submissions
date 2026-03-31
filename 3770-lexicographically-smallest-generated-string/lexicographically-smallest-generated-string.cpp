class Solution {
public:
    bool isSame(vector<char> &word, string & str2, int i, int m) {
        for(int j = 0; j < m; j++) {
            if(word[i] != str2[j]) {
                return false;
            }

            i++;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int wordLen = n+m-1;
        vector<char> word(wordLen, '$');
        vector<bool> can_change(wordLen, false);

        for(int i=0; i<n; i++){
            if(str1[i] == 'T') {
                int temp = i;
                for(int j = 0; j < m; j++) {
                   //word[i] = str2[j]
                   //word[i+1] = str2[j+1] and so on....
                   if(word[temp] != '$' && word[temp] != str2[j]) {
                        return "";
                   }
                   word[temp] = str2[j];
                   temp++;
                }
            }
        }

        // Fill the remaining 'a' and mark them True in can_change
        for(int i=0; i<wordLen; i++){
            if(word[i] == '$') {
                word[i] = 'a';
                can_change[i] = true;
            }
        }

        for(int i=0; i<n; i++){
            if(str1[i]=='F'){
                // if the word and str2 is same we try to
                // change it to next smallest lexicographically string
                if(isSame(word, str2, i, m)) {
                    bool isChanged = false;

                    for(int j=i+m-1; j>=i; j--){
                        if(can_change[j]) {
                            word[j] = 'b';
                            isChanged = true;
                            break;
                        }
                    }

                    if(!isChanged) return "";
                }
            }
        }
        return string(word.begin(), word.end());
    }
};