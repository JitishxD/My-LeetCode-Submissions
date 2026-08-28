class Solution {
    public int countPrimes(int n) {
        if (n <= 2) return 0;

        boolean[] dt = new boolean[n];
        
        for (int i = 2; i * i < n; i++) {
            if (!dt[i]) {
                for (int j = i * i; j < n; j += i) {
                    dt[j] = true;
                }
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (!dt[i]) {
                ans++;
            }
        }

        return ans;
    }
}