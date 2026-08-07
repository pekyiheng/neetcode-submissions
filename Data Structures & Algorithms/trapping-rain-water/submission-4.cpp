class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int tallest = 0;
        int tc = 0;

        for (int i : height) {
            if (i > tallest) {
                tallest = i;
                tc = 1;
            } else if (i == tallest) {
                ++tc;
            }
        }

        while (l+1 < height.size() && height[l+1] > height[l]) {
            ++l;
        }

        while (r-1 > 0 && height[r-1] > height[r]) {
            --r;
        }

        while (height[l] < tallest) {
            int lb = height[l];
            int sumToAdd = 0;
            while (l+1 < height.size() && height[l+1] < lb) {
                sumToAdd += (lb - height[l+1]);
                ++l;
            }
            
            res += sumToAdd;
            ++l;
        }

        while (tc > 1 && l+1 < height.size()) {
            ++l;
            if (height[l] == tallest) {
                --tc;
            } else {
                res += (tallest - height[l]);
            }
        }

        while (height[r] < tallest) {
            int rb = height[r];
            int sumToAdd = 0;
            while (r-1 > 0 && height[r-1] < rb) {
                sumToAdd += (rb - height[r-1]);
                --r;
            }
            
            res += sumToAdd;
            --r;
        }

        return res;
    }
};
