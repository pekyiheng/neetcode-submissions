class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for (int i : nums) {
            s += i;
        }

        if (s % 2 != 0) {
            return false;
        }

        s /= 2;
        unordered_set<int> st;
        st.insert(0);

        for (int n : nums) {
            unordered_set<int> tmp;
            for (int k : st) {
                int c = k+n;
                if (c == s) return true;
                tmp.insert(k+n);
            }
            for (int t : tmp) {
                st.insert(t);
            }
        }

        return st.contains(s);
    }
};
