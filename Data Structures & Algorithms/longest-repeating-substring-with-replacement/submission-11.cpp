class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() < 2) {
            return s.size();
        }

        unordered_map<char, int> m;
        int res = 1;
        int l = 0;
        int hf = 0;


        for (int r = 0; r < s.size(); ++r) {
            ++m[s[r]];
            hf = std::max(m[s[r]], hf);
            if ((r - l) - hf < k) {
                res = std::max(res, r - l + 1);
            } else {
                --m[s[l]];
                ++l;
            }
        }

        return res;
    }
};
