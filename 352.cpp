class SummaryRanges {
public:
    /** Initialize your data structure here. */

    SummaryRanges() {
        res.clear();
        len = 0;
    }

    void addNum(int val) {
        //cout << __func__ << " " << val << endl;
        if (len == 0) res.push_back(vector<int>{val, val});
        else if (res[0][0] > val) {
            if (res[0][0] == val + 1) res[0][0] = val;
            else res.insert(res.begin(), vector<int>{val, val});
        } else if (res[len - 1][1] < val) {
            if (res[len - 1][1] == val - 1) res[len - 1][1] = val;
            else res.push_back(vector<int>{val, val});
        } else {
            int idx = find(val);
            //cout << __func__ << " find " << val << " idx = " << idx << endl;
            if (idx >= 0) {
                if (res[idx][1] == val - 1) {
                    res[idx][1] = val;
                    if (res[idx + 1][0] == val + 1) {
                        res[idx][1] = res[idx + 1][1];
                        res.erase(res.begin() + idx + 1);
                    }
                } else if (res[idx + 1][0] == val + 1){
                    res[idx + 1][0] = val;
                } else {
                    res.insert(res.begin() + idx + 1, vector<int>{val, val});
                }
            }
        }
        len = res.size();
    }

    vector<vector<int>> getIntervals() {
        if (0) {
            for (int i = 0; i < len; i++) {
                cout << res[i][0] << " " << res[i][1] << ", ";
            }
            cout << endl;
        }

        return res;
    }
    //-1: smaller than others; -2: already has this value; others: insert after res[return val]
    int find(int target) {
        int stPos = 0, endPos = len - 1;
        int idx = 0;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (res[midPos][0] > target) {
                endPos = midPos - 1;
            } else if (res[midPos][1] < target) {
                idx = midPos;
                stPos = midPos + 1;
            } else return -2;
        }
        return idx;
    }

private:
    vector<vector<int>> res;
    int len;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */


