class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int len = A.size();
        if (len == 1) return A[0];
        vector<int> left(len, -1);
        vector<int> right(len, len);
        long long res = 0;
        stack<int> stleft;
        stleft.push(0);
        for (int i = 1; i < len; i++) {
            while (!stleft.empty() && A[stleft.top()] > A[i]) {
                stleft.pop();
            }
            if (stleft.empty()) {
                stleft.push(i);
                left[i] = -1;
            } else {
                left[i] = stleft.top();
                stleft.push(i);
            }
        }/*
        for (int i = 0; i < len; i++) {
            cout << left[i] << " ";
        }*/
        cout << endl;
        stack<int> st;
        st.push(len - 1);
        for (int i = len - 2; i >= 0; i--) {
            while (!st.empty() && A[st.top()] >= A[i]) {
                st.pop();
            }
            if (st.empty()) {
                st.push(i);
                right[i] = len;
            } else {
                right[i] = st.top();
                st.push(i);
            }
        }/*
        for (int i = 0; i < len; i++) {
            cout << right[i] << " ";
        }
        cout << endl;*/
        for (int i = 0; i < len; i++) {
            res = res + (i - left[i]) * (right[i] - i) * A[i];
            //cout << res << endl;
            res = res % maxn;
        }
        return res;
    }
private:
    int maxn = 1000000007;
};
