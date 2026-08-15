class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for (const string& t : tokens) {
            if (t == "+") {
                int f = st.top();
                st.pop();
                int s = st.top();
                st.pop();
                st.push(f + s);
            } else if (t == "-") {
                int f = st.top();
                st.pop();
                int s = st.top();
                st.pop();
                st.push(s - f);

            } else if (t == "*") {
                int f = st.top();
                st.pop();
                int s = st.top();
                st.pop();
                st.push(f * s);

            } else if (t == "/") {
                int f = st.top();
                st.pop();
                int s = st.top();
                st.pop();
                st.push(s / f);
            } else {
                int j = std::stoi(t);
                st.push(j);
            }
        }

        return st.top();
    }
};
