#include <vector>
#include <stack>

// 739. Daily Temperatures

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> idx; // store index
        for (int i = 0; i < n; ++i) {
            while (!idx.empty() && temperatures[i] > temperatures[idx.top()]) {
                ans[idx.top()] = i - idx.top();
                idx.pop();
            }
            idx.push(i);
        }
        return ans;
    }
};