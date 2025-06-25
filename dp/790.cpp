#include <vector>


using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        vector<int> res(n+1);
        res[1] = 1, res[2] = 2, res[3] = 5;
        int i = 4;
        int mod = 1e9 + 7;
        while (i <= n) {
            res[i] = (res[i-1]*2 + 1L * res[i-3]) % mod;
            i++;
        }
        return res[n];
    }
};