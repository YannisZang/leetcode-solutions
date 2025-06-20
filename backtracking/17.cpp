#include <vector>
#include <string>

// 17. Letter Combinations of a Phone Number

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> res;
        if (digits.size() == 0) return res;

        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtracking(map, digits, 0, res, "");

        return res;

    }

    void backtracking(string map[], string& digits, int idx, vector<string>& res, string ans) {
        if (idx == digits.length()) {
            res.push_back(ans);
            return;
        }

        int i = digits[idx] - '0';
        string letter = map[i];

        for (int j = 0; j < letter.length(); ++j) {
            ans.push_back(letter[j]);
            backtracking(map, digits, idx+1, res, ans);
            ans.pop_back();
        }
    }

    // vector<string> letterCombinations(string digits) {

    //     if (digits.length() == 0) return {};

    //     unordered_map<char, string> letters = {
    //         {'2', "abc"},
    //         {'3', "def"},
    //         {'4', "ghi"},
    //         {'5', "jkl"},
    //         {'6', "mno"},
    //         {'7', "pqrs"},
    //         {'8', "tuv"},
    //         {'9', "wxyz"}
    //     };

    //     vector<string> ans;

    //     backtracking(letters, digits, 0, "", ans);

    //     return ans;

        
    // }

    // void backtracking(const unordered_map<char, string>& letters, string& digits, int idx, string res, vector<string>& ans) {
    //     if (idx == digits.length()) {
    //         ans.push_back(res);
    //         return;
    //     }
            

    //     string letter = letters.at(digits[idx]);

    //     for (auto l : letter) {
    //         backtracking(letters, digits, idx+1, res+l, ans);
    //     }
    // }
};