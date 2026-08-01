class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9, unordered_set<char>());
        vector<unordered_set<char>> col(9, unordered_set<char>());
        vector<unordered_set<char>> cube(9, unordered_set<char>());

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }

                if (!row[i].insert(c).second || 
                    !col[j].insert(c).second || 
                    !cube[(i / 3) * 3 + (j / 3)].insert(c).second) {
                        return false;
                    }
            }
        }

        return true;
        
    }
};
