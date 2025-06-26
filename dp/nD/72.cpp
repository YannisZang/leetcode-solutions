#include <vector>

// 72. Edit Distance

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size()+1;
        int col = word2.size()+1;
        
        vector<vector<int>> grid(row, vector<int> (col, 0));

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {

                if (c == 0) grid[r][c] = r;

                else if (r == 0) grid[r][c] = c;

                else if ( word1[r-1] == word2[c-1])     
                    grid[r][c] = grid[r-1][c-1];
                    
                else     
                    grid[r][c] = min({grid[r-1][c], grid[r][c-1], grid[r-1][c-1]}) + 1;
                                     // delete.     insert.       replace
                    
            }
        }
        return grid[row-1][col-1];
    }
};