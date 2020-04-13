class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        len = persons.size();
        ptimes = times;
        res.resize(len);
        res[0] = persons[0];
        vector<int> calc;
        calc.resize(len + 1);
        calc[persons[0]] = 1;
        for (int i = 1; i < len; i++) {
            calc[persons[i]]++;
            if (calc[persons[i]] >= calc[res[i - 1]]) {
                res[i] = persons[i];
            } else {
                res[i] = res[i - 1];
            }
        }
    }

    int q(int t) {
        int stPos = 0, endPos = len - 1;
        int pos = -1;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (ptimes[midPos] > t) {
                endPos = midPos - 1;
            } else {
                pos = midPos;
                stPos = midPos + 1;
            }
        }
        if (pos == -1) return 0;
        
        return res[pos];
    }

private:
    vector<int> ptimes;
    vector<int> res;
    int len;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
