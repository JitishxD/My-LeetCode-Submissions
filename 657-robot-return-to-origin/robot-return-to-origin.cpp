class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0, j=0;

        for(char c: moves){
            if(c=='U') i++;
            if(c=='D') i--;
            if(c=='L') j++;
            if(c=='R') j--;
        }

        if(i!=0 || j!=0) return false;

        return true;
    }
};