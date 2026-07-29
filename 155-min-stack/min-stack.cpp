class MinStack {
public:
    stack<long long> st;
    long long minVal = LLONG_MAX;

    MinStack() {}

    void push(int value) {
        long long val = value;              // promote to long long first
        if (st.empty()) {
            minVal = val;
            st.push(val);
        } else {
            if (val >= minVal) {
                st.push(val);
            } else {
                st.push(2*val - minVal);     // now safe, done in long long
                minVal = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (st.empty()) {
            minVal = LLONG_MAX;
            return;
        }
        if (x < minVal) {
            minVal = 2*minVal - x;
        }
    }

    int top() {
        if (st.empty()) return 0;
        long long x = st.top();              // keep as long long!
        if (x < minVal) return (int)minVal;
        else return (int)x;
    }

    int getMin() {
        return (int)minVal;
    }
};