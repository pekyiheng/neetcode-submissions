class Solution {
public:
    int climbStairs(int n) {
        int cur = 1;
        int next = 2;

        if (n < 3) {
            return n;
        }

        for (int i = 2; i < n; ++i) {
            int tmp = next;
            next = cur + next;
            cur = tmp;
        }

        return next;
        
    }
};
