class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        //check row
        for (auto& row : board) {
            unordered_set<char> s;
            for (char c : row) {
                if (c != '.' && (!s.insert(c).second)) {
                    std::cout << c << "\n" ;
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; ++i) {
            unordered_set<char> s;
            for (int j = 0; j < 9; ++j) {
                char c = board[j][i];
                if (c != '.' && (!s.insert(c).second)) {
                    std::cout << c << "\n" ;
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int k = 0; k < 9; k += 3) {
                unordered_set<char> s;
                for (int r = 0; r < 3; ++r) {
                    for (int col = 0; col < 3; ++col) {
                        char c = board[r+i][col+k];
                        if (c != '.' && (!s.insert(c).second)) {
                            std::cout << c << "\n" ;
                            return false;
                        }
                    }
                }
            }
        }

        return true;
        
    }
};
