class Solution {
public:
    bool isValid(string s) {
        vector<char> v(s.size());
        int i = 0;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                v[i] = ch;
                ++i;
            } else {
                if (i < 1) {
                    return false;
                }
                --i;
                auto c = v[i];
                if (c == '(' && ch != ')') {
                    return false;
                } else if (c == '[' && ch != ']') {
                    return false;
                } else if (c == '{' && ch != '}') {
                    return false;
                }

            }
        }

        return i  == 0;
    }
};
