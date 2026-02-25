class Solution {
public:
    int nonZeroBits(int n) {
        // Brian Kernighan’s Algorithm
        int count;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> bitsCount;
        for (int i = 0; i < arr.size(); i++) {
            int c = nonZeroBits(arr[i]);
            bitsCount[arr[i]] = c;
        }
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (bitsCount[a] == bitsCount[b])
                return a < b;
            return bitsCount[a] < bitsCount[b];
        });
        
        return arr;
    }
};