class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto v = vector<int>(nums.size() - k + 1);
        int maxVal = -100001;
        unordered_map<int, int> m;

        for (int i = 0; i < k; ++i) {
            ++m[nums[i]];
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }
        v[0] = maxVal;
        int l = 0;
        for (int r = k; r < nums.size(); ++r) {
            --m[nums[l]];
            ++m[nums[r]];
            if (nums[r] > maxVal) {
                maxVal = nums[r];
            } else if (nums[l] == maxVal) {
                if (m[nums[l]] < 1) {
                    maxVal = -100001;
                    for (auto x : m) {
                        if (x.second > 0 && x.first > maxVal) {
                            maxVal = x.first;
                        }
                    }
                }
            }
            ++l;
            v[l] = maxVal;
        }

        return v;
    }
};
