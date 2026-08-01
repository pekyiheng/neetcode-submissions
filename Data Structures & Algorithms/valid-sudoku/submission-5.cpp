class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int cube[9] = {0};

        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }

                int val = c - '1';

                if ((row[i] >> val) & 1|| 
                    (col[j] >> val) & 1 || 
                    (cube[(i / 3) * 3 + (j / 3)] >> val) & 1) {
                        return false;
                    }
                
                row[i] |= 1 << val;
                col[j] |= 1 << val;
                cube[(i / 3) * 3 + (j / 3)] |= 1 << val;
            }
        }

        return true;
        
    }
};
