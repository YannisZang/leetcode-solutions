#include <unordered_set>
#include <vector>
#include <string>

// 51. N-Queens

using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        unordered_set<int> col;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        vector<string> ans (n, string(n, '.'));
        backtrack(res, col, diag1, diag2, n, 0, ans);

        return res;

    }

    void backtrack(vector<vector<string>>& res, unordered_set<int>& col, unordered_set<int>& diag1, unordered_set<int>& diag2, const int& n, int row, vector<string>& ans) {
        if (row == n) {
            res.push_back(ans);
            return;
        }
        
        for (int i = 0; i < n; ++i) {

            if (col.count(i) || diag1.count(row-i) || diag2.count(row+i)) continue;

            // chose queen in row
            col.insert(i);
            diag1.insert(row-i);
            diag2.insert(row+i);
            ans[row][i] = 'Q';
            
            backtrack(res, col, diag1, diag2, n, row+1, ans);
            
            col.erase(i);
            diag1.erase(row-i);
            diag2.erase(row+i);
            ans[row][i] = '.';
        }
        
    }
};