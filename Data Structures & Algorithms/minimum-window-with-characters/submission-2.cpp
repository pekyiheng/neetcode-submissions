class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> m;
        for (char x : t) {
            ++m[x];
        }

        int needed = 0;
        for (auto _ : m) {
            ++needed;
        }
        int satisfied = 0;
        pair<int, int> p = {0, s.size()};
        int l = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            if (m.contains(s[r])) {
                if (m[s[r]] == 1) {
                    ++satisfied;
                }
                --m[s[r]];
            }
            if (satisfied == needed) {
                
                while (!m.contains(s[l]) || m[s[l]] < 0) {
                    if (m.contains(s[l])) {
                        ++m[s[l]];
                    }
                    ++l;
                }
                if ((r - l) < (p.second - p.first)) {
                    p = {l, r};
                }
                ++m[s[l]];
                ++l;
                --satisfied;
            }
        }

        if (s.size() == p.second) {
            return "";
        }
        return s.substr(p.first, 1 + p.second - p.first);

    }
};
