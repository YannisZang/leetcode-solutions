#include <vector>

// 1143. Longest Common Subsequence

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.length()+1;
        int cols = text2.length()+1;
        vector<vector<int>> grid(rows, vector<int> (cols, 0));
        for (int r = 1; r < rows; ++r) {
            for (int c = 1; c < cols; ++c) {
                int ans = std::max(grid[r-1][c], grid[r][c-1]);
                if (text1[r-1] == text2[c-1]) {
                    grid[r][c] = grid[r-1][c-1]+1;
                }
                else
                    grid[r][c] = ans;
            }
        }
        return grid[rows-1][cols-1];

    }
};