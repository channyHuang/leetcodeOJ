class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int len = asteroids.size();
        if (len <= 0) return res;
        if (len == 1) return asteroids;
        stack<int> st;
        st.push(asteroids[0]);
        for (int i = 1; i < len; i++) {
            if (st.empty() || asteroids[i] * st.top() > 0 || (asteroids[i] > 0 && st.top() < 0)) {
                st.push(asteroids[i]);
                continue;
            }
            if (abs(asteroids[i]) > abs(st.top())) {
                st.pop();
                i--;
                continue;
            } else if (abs(asteroids[i]) == abs(st.top())) {
                st.pop();
                continue;
            }
        }
        int pos = st.size();
        if (pos == 0) return res;
        res.resize(pos);
        pos--;
        while (!st.empty()) {
            res[pos--] = st.top();
            st.pop();
        }
        return res;
    }
};
