class Solution {
public:
    class Node {
    public:
        vector<int> value;
        int index;
        Node(int _idx = 0, vector<int> _value = vector<int>(3, 0)) {
            index = _idx;
            value = _value;
        }
    };

    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        lenInc = increase.size();
        lenReq = requirements.size();
        vector<int> res(lenReq, -1);
        for (int i = 0; i < lenReq; i++) {
            if (requirements[i][0] == 0 && requirements[i][1] == 0 && requirements[i][2] == 0) {
                res[i] = 0;
            }
            vec.push_back(Node(i, requirements[i]));
        } 
        sort(vec.begin(), vec.end(), cmp);          
        vector<int> cur(3, 0);
        int pos = 0;
        for (int i = 0; i < lenInc; i++) {
            for (int j = 0; j < 3; j++) {
                cur[j] += increase[i][j];
            }
            for (int j = pos; j < lenReq; j++) {
                if (vec[j].value[0] > cur[0]) break;
                if (res[vec[j].index] != -1) {
                    if (j == pos) pos++;
                    continue;
                }
                if (vec[j].value[1] <= cur[1] && vec[j].value[2] <= cur[2]) {
                    res[vec[j].index] = i + 1;
                    if (j == pos) pos++;
                }
            }
        }
        return res;
    }

    static bool cmp(const Node& a, const Node& b) {
        if (a.value[0] == b.value[0]) {
            if (a.value[1] == b.value[1]) {
                return a.value[2] < b.value[2];
            }
            return a.value[1] < b.value[1];
        }
        return a.value[0] < b.value[0];
    }

private:
    int lenInc, lenReq;
    vector<Node> vec;
};
