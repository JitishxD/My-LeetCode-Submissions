class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n/rows;
        string ans = "";

        for(int i=0; i<cols; i++){
            int r=0, c=i;
            while(r<rows && c<cols){
                ans += encodedText[r*cols+c];
                r++;
                c++;
            }
        }

        // remove trailing spaces
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }


        return ans;
    }
};