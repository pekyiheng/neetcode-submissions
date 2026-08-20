class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = 0;
        int b = matrix.size() - 1;
        int n = matrix[0].size();

        while (t <= b) {
            int midr = (t + b) / 2;
            if (target >= matrix[midr][0] && target <= matrix[midr][n-1]) {
                int l = 0;
                int r = n - 1;

                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (target == matrix[midr][mid]) {
                        return true;
                    } else if (target < matrix[midr][mid]) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }

                return false;

            } else if (target < matrix[midr][0]) {
                b = midr - 1;
            } else {
                t = midr + 1;
            }
        }

        return false;
    }
};
