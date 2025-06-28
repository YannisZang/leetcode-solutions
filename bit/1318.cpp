#include <bit>


using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 1;
        int count = 0;
        while (c > 0 || a > 0 || b> 0) {
            int a_flip = a&flip;
            int b_flip = b&flip;
            int c_flip = c&flip;
            if ((a_flip | b_flip) != c_flip) {
                if (c_flip == 0) count += (a_flip != 0) + (b_flip != 0);
                else if (c_flip == 1) count++;
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return count;
    }
    // int minFlips(int a, int b, int c) {
    //     unsigned long long x = ((unsigned long long)(c ^ (a | b)) << 32) | (a & b & c);
    //     return __builtin_popcountll(x);
    // }

};