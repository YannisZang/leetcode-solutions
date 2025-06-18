#include <queue>

// 2462. Total Cost to Hire K Workers

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> head, tail;
        queue<int> cheapest;
        long long ans = 0;
        int can = 0;

        int start = 0, end = n-1;

        while (start <= end && k > 0) {
            
            if (start >= candidates) {
                if (head.top() <= tail.top()) {
                    ans += head.top();
                    head.pop();
                    head.push(costs[start++]);
                }
                else {
                    ans += tail.top();
                    tail.pop();
                    tail.push(costs[end--]);
                }
                k--;               
            }
            else if (start == end) {
                head.push(costs[start++]);
            }
            else {
                head.push(costs[start++]);
                tail.push(costs[end--]);
            }
        }
        while (k-- > 0) {
            int l = head.empty() ? INT_MAX : head.top();
            int r = tail.empty() ? INT_MAX : tail.top();
            if (l <= r) {
                ans += l;
                head.pop();
            }
            else {
                ans += r;
                tail.pop();
            }
        }
        return ans;
    }
};