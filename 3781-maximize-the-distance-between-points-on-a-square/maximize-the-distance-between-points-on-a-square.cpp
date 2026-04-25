#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    long long map_to_1D(long long x, long long y, long long side) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 3LL * side - x;
        if (x == 0) return 4LL * side - y;
        return 0;
    }

    bool check(long long D, int N, int k, const vector<long long>& d, long long P) {
        vector<int> nxt(2 * N, 2 * N);
        int j = 0;
        
        // Precompute the next valid point for a jump of at least D
        for (int i = 0; i < 2 * N; ++i) {
            while (j < 2 * N && d[j] - d[i] < D) {
                j++;
            }
            nxt[i] = j;
        }
        
        // Try starting the sequence from every possible initial point
        for (int i = 0; i < N; ++i) {
            int curr = i;
            bool ok = true;
            for (int step = 0; step < k - 1; ++step) {
                curr = nxt[curr];
                if (curr >= 2 * N) {
                    ok = false;
                    break;
                }
            }
            // Check if the wrap-around distance is also at least D
            if (ok && d[curr] - d[i] <= P - D) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int N = points.size();
        vector<long long> d(N);
        
        for (int i = 0; i < N; ++i) {
            d[i] = map_to_1D(points[i][0], points[i][1], side);
        }
        
        sort(d.begin(), d.end());
        
        // Double the array to smoothly handle circular distances
        long long P = 4LL * side;
        vector<long long> doubled_d(2 * N);
        for (int i = 0; i < N; ++i) {
            doubled_d[i] = d[i];
            doubled_d[i + N] = d[i] + P;
        }
        
        long long low = 1, high = side, ans = 1;
        
        // Binary search the optimal minimum distance
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, N, k, doubled_d, P)) {
                ans = mid;
                low = mid + 1; // Try to find a larger minimum distance
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};