class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res;
        res.resize(n);
        stack<pair<int, int>> st;
        int curTime = 0;
        bool curOp = true; //true: start, false: end
        for (int i = 0; i < logs.size(); i++) {
            string::size_type pos = logs[i].find_first_of(":");
            int funId = 0;
            for (int j = 0; j < pos; j++) funId = funId * 10 + logs[i][j] - '0';
            string::size_type nextPos = logs[i].find_first_of(":", pos + 1);
            string op = logs[i].substr(pos + 1, nextPos - pos - 1);
            int time = 0;
            for (int j = nextPos + 1; j < logs[i].length(); j++) time = time * 10 + logs[i][j] - '0';

            if (op == "start") {
                if (!st.empty()) {
                    pair<int, int> curPair = st.top();
                    res[curPair.first] += (time - curTime);
                }
                pair<int, int> curPair(funId, time);
                st.push(curPair);
                curTime = time;
            } else {
                pair<int, int> curPair = st.top();
                st.pop();
                res[curPair.first] += (time - curTime + 1);
                curTime = time + 1;
            }
        }
        return res;
    }
};
