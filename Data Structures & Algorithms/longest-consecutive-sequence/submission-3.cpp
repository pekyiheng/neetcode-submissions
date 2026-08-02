class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int highest = 0;
        unordered_map<int, pair<int, int>> m;

        for (int num : nums) {
            if (m.count(num) > 0) {
                continue;
            }

            int l = num;
            int r = l;

            if (m.count(num - 1) > 0) {
                l = m[num -1].first;
            }

            if (m.count(num + 1) > 0) {
                r = m[num + 1].second;
            }

            m[num] = {l, r};
            m[l] = {l, r};
            m[r] = {l, r};

            int cur = (r - l) + 1;

            if (cur > highest) {
                highest = cur;
            }
        }

        return highest;
    }
};
