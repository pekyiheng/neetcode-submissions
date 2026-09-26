class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int p = nums.size();
        int kk = k-1;

        while (p != kk) {
            p = partition(nums, l, r);
            if (p == kk) {return nums[p];}
            if (p < kk) {
                l = p+1;
            } else {
                r = p-1;
            }
        }

        return nums[p];
    }

    int partition(vector<int>& n, int l, int r) {
        int pv = n[r];
        int i = l;
        for (int j = l; j < r; ++j) {
            if (n[j] > pv) {
                swap(n[i], n[j]);
                ++i;
            }
        }

        swap(n[i], n[r]);
        return i;
    }
};
