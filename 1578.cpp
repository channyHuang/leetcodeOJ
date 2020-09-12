class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int len = s.length();
        stack<pair<char, int>> st;
        int i = 0;
        int res = 0;
        st.push(pair<char, int>(s[i], cost[i]));
        for (i = 1; i < len; i++) {
            if (st.empty() || st.top().first != s[i]) {
                st.push(pair<char, int>(s[i], cost[i]));
            } else if (st.top().second <= cost[i]){
                res += st.top().second;
                st.pop();
                st.push(pair<char, int>(s[i], cost[i]));
            } else {
                res += cost[i];
            }
        }
        return res;
    }
};
