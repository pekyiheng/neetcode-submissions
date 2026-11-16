class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i) {
            int dl = i, dr = i;
            while (dl >= 0 && dr < s.size()) {
                if (s[dl] != s[dr]) {
                    break;
                }
                dl--;
                dr++;
            }
            
            ++dl;
            --dr;
            if (dr - dl > longest) {
                l = dl;
                r = dr;
                longest = r - l;
            }

            if (i+1 >= s.size() || s[i] != s[i+1]) {
                continue;
            }

            dl = i, dr = i+1;
            while (dl >= 0 && dr < s.size()) {
                if (s[dl] != s[dr]) {
                    break;
                }
                dl--;
                dr++;
            }
            
            ++dl;
            --dr;
            if (dr - dl > longest) {
                l = dl;
                r = dr;
                longest = r - l;
            }

        }

        return s.substr(l, r - l + 1);
    }
};
