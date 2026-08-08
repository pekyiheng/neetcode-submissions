class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int l = 0;
        int r = 1;
        unordered_map<char, int> seen;

        if (s.size() < 2) {
            return s.size();
        }

        seen[s[l]] = l;
        while (r < s.size()) {
            if (seen.contains(s[r]) && seen[s[r]] >= l) {
                maxlen = std::max(maxlen, r - l);                
                l = seen[s[r]] + 1;
            }
            
            seen[s[r]] = r;
            ++r;
        }
        maxlen = std::max(maxlen, r - l);
        return maxlen;
    }
};
