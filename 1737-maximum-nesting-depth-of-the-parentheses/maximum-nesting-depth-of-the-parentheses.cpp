class Solution {
public:
    int maxDepth(string s) {
        int counter = 0;
        int maxCounter = 0;
        for(char c: s){
            if(c=='(') counter++;
            else if (c==')') counter--;

            maxCounter = max(maxCounter, counter);
        }

        return maxCounter;
    }
};