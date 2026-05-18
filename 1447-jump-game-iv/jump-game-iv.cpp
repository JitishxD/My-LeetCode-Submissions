#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return 0;
        }

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }

        vector<int> curs; // store current layer
        curs.push_back(0);
        
        vector<bool> visited(n, false);
        visited[0] = true; // Mark starting node as visited
        int step = 0;

        // when current layer exists
        while (!curs.empty()) {
            vector<int> nex;

            // iterate the layer
            for (int node : curs) {
                // check if reached end
                if (node == n - 1) {
                    return step;
                }

                // check same value
                for (int child : graph[arr[node]]) {
                    if (!visited[child]) {
                        visited[child] = true;
                        nex.push_back(child);
                    }
                }

                // clear the list to prevent redundant search
                graph[arr[node]].clear();

                // check neighbors
                if (node + 1 < n && !visited[node + 1]) {
                    visited[node + 1] = true;
                    nex.push_back(node + 1);
                }
                if (node - 1 >= 0 && !visited[node - 1]) {
                    visited[node - 1] = true;
                    nex.push_back(node - 1);
                }
            }

            curs = std::move(nex);
            step++;
        }

        return -1;
    }
};