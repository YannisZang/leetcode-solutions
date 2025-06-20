#include <vector>
#include <string>

// 216. Combination Sum III

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> res;

        vector<int> ans;

        if (n)
            backtracking(k, n, 1, 0, res, ans);
        
        return res;

    }

    void backtracking(const int& k, const int& n, int idx, int sum, vector<vector<int>>& res, vector<int>& ans) {
        if (sum > n) return;
        if (ans.size() == k) {
            // sum += idx;
            if (sum == n) 
                res.push_back(ans);
            return;
        }
        for (int i = idx; i < 10; ++i) {
            ans.push_back(i);
            backtracking(k, n, i+1, sum + i, res, ans);
            ans.pop_back();
        }
    }
};