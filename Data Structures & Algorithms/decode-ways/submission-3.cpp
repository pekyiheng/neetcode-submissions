class Solution {
public:
    int numDecodings(string s) {
        int singles = 0;
        int doubles = 0;

        if (s[0] == '0') {
            return 0;
        } else {
            singles = 1;
        }

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (!(s[i-1] == '1' || s[i-1] == '2')) {
                    return 0;
                }
                doubles = singles;
                singles = 0;
            } else {
                if (canMatch(s[i-1], s[i])) {
                    int tmp = singles;
                    singles += doubles;
                    doubles = tmp;
                } else {
                    singles += doubles;
                    doubles = 0;
                }
            }

        }

        return singles + doubles;
    }

    bool canMatch(char l, char r) {
        if (l == '0') {
            return false;
        }

        int li = l - '0';
        int ri = r - '0';

        return ((li * 10) + ri) <= 26;
    }
};
