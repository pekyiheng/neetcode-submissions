class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (!std::isalnum(static_cast<unsigned char>(s[l]))) {
                ++l;
            }

            while (!std::isalnum(static_cast<unsigned char>(s[r]))) {
                --r;
            }

            if (l > r) {
                return true;
            }

            char lc = s[l];
            char rc = s[r];

            if (std::isupper(lc)) {
                lc = std::tolower(lc);
            }

            if (std::isupper(rc)) {
                rc = std::tolower(rc);
            }

            if (lc != rc) {
                return false;
            }
            ++l;
            --r;

        }
        return true;
    }
};
