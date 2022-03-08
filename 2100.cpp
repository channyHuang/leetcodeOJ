class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> res;
        int len = security.size();
		if (time <= 0) {
			for (int i = 0; i < len; ++i) {
				res.push_back(i);
			}
			return res;
		}
        if (len <= time + time) return res;
        int stpos = 0, left, right, pos;
        do {
            for (pos = stpos + 1; pos <= stpos + time; pos++) {
                if (security[pos] > security[pos - 1]) {
                    stpos = pos;
                    pos = stpos;
                    if (stpos + time + time >= len) return res;
                }
            }
            // pre time days valid
            int bhasup = -1;
            for (pos = stpos + time + 1; pos <= stpos + time + time; pos++) {
                if (security[pos] > security[pos - 1]) {
                    if (bhasup == -1) bhasup = pos;
                } else if (security[pos] < security[pos - 1]) {
                    if (bhasup >= 0) {
                        stpos = bhasup;
                        break;
                    } else {
                        stpos = pos - time;
                        if (stpos + time + time >= len) return res;
                        pos = stpos + time;
                    }
                }
            }
            if (pos > stpos + time + time) {
                // next time days valid
                res.push_back(stpos + time);
                pos = stpos + time + 1;
                while (pos < len - time) {
                    if (security[pos] <= security[pos - 1] && security[pos + time] >= security[pos + time - 1]) {
                        res.push_back(pos);
                    } else if (security[pos] > security[pos - 1]) {
                        stpos = pos;
                        break;
                    } else {
                        stpos = pos - time;
                        break;
                    }
                    pos++;
                }
                if (pos >= len - time) break;
            }
        } while (stpos + time + time < len);
        return res;
    }
};
