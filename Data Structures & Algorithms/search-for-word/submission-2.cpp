class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> boardVisited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] != word[0]) {
                    continue;
                }
                res |= dfs(board, word, 0, r, c, boardVisited);
                if (res) {
                    return res;
                }
            }
        }
        return res;

    }

    bool dfs(vector<vector<char>>& board, string& word, int idx, int r, int c, vector<vector<bool>>& boardVisited) {
        vector<pair<int, int>> vp = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        if (r < 0 || r >= board.size()) {
            return false;
        }

        if (c < 0 || c >= board[0].size()) {
            return false;
        }

        if (boardVisited[r][c]) {
            return false;
        }

        if (board[r][c] != word[idx]) {
            return false;
        }

        if (idx == word.size() - 1) {
            return true;
        }

        bool ret = false;
        boardVisited[r][c] = true;
        for (auto& p : vp) {
            int nr = r + p.first;
            int nc = c + p.second;
            
            ret |= dfs(board, word, idx+1, nr, nc, boardVisited);
        }
        boardVisited[r][c] = false;
        return ret;
    }
};
