class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        int l = 0;
        unordered_map<char, int> m;

        for (int i = 0; i < s1.size(); ++i) {
            ++m[s1[i]];
        }

        int needed = m.size();
        int satisfied = 0;
        
        for (int r = 0; r < s2.size(); ++r) {
            if (m.contains(s2[r])) {
                --m[s2[r]];
                if (m[s2[r]] == 0) {
                    ++satisfied;
                }
            }

            if (satisfied == needed) {
                return true;
            }

            if (r - l == s1.size() - 1) {
                if (m.contains(s2[l])) {
                    ++m[s2[l]];
                    if (m[s2[l]] == 1) {
                        --satisfied;
                    }
                }
                ++l;
            }
        }

        return false;        

    }
};
