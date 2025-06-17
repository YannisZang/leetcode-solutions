#include <vector>
#include <queue>

using namespace std;

// 994. Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int num_fresh = 0;
        int ans = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 2) rotten.push({i, j});
                else if (grid[i][j] == 1) num_fresh++;
            }
        }
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        // case: no fresh orange at beginning
        if (num_fresh == 0) return ans;

        while (!rotten.empty()) {
            if (num_fresh == 0) return ans;
            int n = rotten.size();
            ans++;
            while (n-- > 0) {
                int r = rotten.front().first;
                int c = rotten.front().second;
                rotten.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = r+dx[k];
                    int y = c+dy[k];
                    if (x >=0 && y >= 0 && x < row && y < col && grid[x][y] == 1) {
                        rotten.push({x, y});
                        grid[x][y] = 2;
                        num_fresh--;
                    }
                }
             }
        }
        return -1;     
    }
};