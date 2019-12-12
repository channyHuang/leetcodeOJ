class Solution {
public:
    string removeDuplicates(string S) {
        int len = S.length();
		string res;
		stack<char> st;
		for (int i = 0; i < len; i++) {
			if (st.empty()) st.push(S[i]);
			else if (st.top() == S[i]) st.pop();
			else st.push(S[i]);
		}
        len = st.size();
		res.resize(len);
		while (!st.empty()) {
			res[--len] = st.top();
			st.pop();
		}
		return res;
    }
};
