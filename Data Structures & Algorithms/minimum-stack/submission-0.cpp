class MinStack {
public:
std::stack<int> st;
unordered_map<int, int> m;
int min = INT_MAX;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        min = std::min(min, val);
        ++m[val];
    }
    
    void pop() {
        int tp = st.top();
        --m[tp];
        st.pop();
        if (m[tp] == 0) {
            min = INT_MAX;
            for (auto x : m) {
                if (x.second > 0 && x.first < min) {
                    min = x.first;
                }
            }
        }        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};
