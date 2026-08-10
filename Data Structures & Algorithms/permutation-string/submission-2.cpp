class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        int freq[26] = {0};
        for (char c : s1) {
            ++freq[c - 'a'];
        }
        
        int needed = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) ++needed;
        }
        
        int satisfied = 0, l = 0;
        
        for (int r = 0; r < s2.size(); ++r) {
            int idx = s2[r] - 'a';
            if (freq[idx] == 1) ++satisfied;
            --freq[idx];
            
            if (r - l + 1 > (int)s1.size()) {
                int lidx = s2[l] - 'a';
                if (freq[lidx] == 0) --satisfied;
                ++freq[lidx];
                ++l;
            }
            
            if (satisfied == needed) {
                return true;
            }
        }
        
        return false;
    }
};