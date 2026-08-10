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
        
        for (int r = 0; r < s2.size(); ++r) {
            if (m.contains(s2[r])) {
                --m[s2[r]];
            }

            if (r - l == s1.size() - 1) {
                bool found = true;
                for (auto x : m) {
                    // std::cout << "ch : " << x.first << " cnt: " << x.second << "\n";
                    if (x.second > 0) {
                        found = false;
                    }
                }
                // std::cout << "-\n";

                if (found) {
                    // std::cout << "l : " << l << " r: " << r << "\n";
                    return found;
                }

                if (m.contains(s2[l])) {
                    ++m[s2[l]];
                }
                ++l;
            }
        }

        return false;        

    }
};
