#include <utility>
#include <vector>

// 1466. Reorder Routes to Make All Paths Lead to the City Zero


using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        int ans = 0;
        
        for (auto path : connections) {
            adj[path[1]].push_back({path[0], 0}); // 0 means 0 -> 1
            adj[path[0]].push_back({path[1], 1});
        }
        dfs(adj, 0, -1, ans);
        return ans;
    }

    void dfs(vector<vector<pair<int, int>>>& adj, int node, int parent, int& ans) {
        for (auto [neighbor, sign] : adj[node]) {
            if (neighbor != parent) {
                ans += sign;
                dfs(adj, neighbor, node, ans);
            }    
        }
    }
};