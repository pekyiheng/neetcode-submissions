class MinStack {
public:
std::stack<int> st;
std::stack<int> mst;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if (mst.empty() || val <= mst.top()) {
            mst.push(val);
        }
       
    }
    
    void pop() {
        if (st.top() == mst.top()) {
            mst.pop();
        }
        st.pop();   
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};
