class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto res = vector<int>(temperatures.size(), 0);
        std::stack<pair<int, int>> st;

        for (int i = 0; i < temperatures.size(); ++i) {
            int t = temperatures[i];
            if (!st.empty()) {
                auto tp = st.top();
                while (!st.empty() && t > st.top().first) {
                    res[tp.second] = i - tp.second;
                    st.pop();
                    tp = st.top();
                }
            }
            st.push(pair(t, i));
        }

        return res;
    }
};
