
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
		int len = S.length();
		int st = 0, end = len;
		res.resize(len + 1);
		for (int i = len; i >= 1; i--) {
			if (S[i - 1] == 'I') res[i] = end--;
			else res[i] = st++;
		}
		res[0] = st;
		return res;
	}
};
