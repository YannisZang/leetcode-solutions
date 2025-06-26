#include <vector>

// 714. Best Time to Buy and Sell Stock with Transaction Fee

using namespace std;

class Solution {
public:
    // int maxProfit(vector<int>& prices, int fee) {
    //     int buy = INT_MIN;
    //     int sell = 0;

    //     for (int price : prices) {
    //         buy = max(buy, sell - price);
    //         sell = max(sell, buy + price - fee);
    //     }

    //     return sell;
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy (n, 0);
        vector<int> sell (n, 0);
        buy[0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee);
        }

        return sell[n-1];
    }
};