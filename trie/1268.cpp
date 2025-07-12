#include <vector>
#include <string>

// 1268. Search Suggestions System

using namespace std;


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int bsStart = 0, start;
        string prefix;
        for (char& c : searchWord) {
            prefix += c;
            start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();

            ans.push_back({});

            for (int i = start; i < min(n, start+3) && !products[i].compare(0, prefix.size(), prefix); ++i) {
                ans.back().push_back(products[i]);
            }
            bsStart = start;
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//         sort(products.begin(), products.end());
//         int size = searchWord.length();
//         vector<vector<string>> ans(size);
//         int a = 0, b = products.size() - 1;
//         for (int i = 0; i < size && a <= b; ++i) {
//             while (a <= b && (products[a].size() <= i || products[a][i] != searchWord[i])) a++;
//             while (a <= b && (products[b].size() <= i || products[b][i] != searchWord[i])) b--;

//             for (int k = a; k <= min(b, a+2); ++k) 
//                 ans[i].push_back(products[k]);   
//         }

//         return ans;
//     }
// };