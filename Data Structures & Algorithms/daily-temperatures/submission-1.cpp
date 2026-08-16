class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto res = vector<int>(temperatures.size(), 0);
        std::stack<pair<int, int>> st;

        for (int i = 0; i < temperatures.size(); ++i) {
            int t = temperatures[i];
            while (!st.empty() && t > st.top().first) {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push(pair(t, i));
        }

        return res;
    }
};
