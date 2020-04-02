class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int len = tree.size();
        if (len <= 2) return len;
        int res = 2;
        int stPos[2] = {-1, -1};
        int endPos[2] = {-1, -1};
        stPos[0] = 0;
        endPos[0] = 0;
        int i;
        for (i = 1; i < len; i++) {
            if (tree[i] == tree[stPos[0]]) {
                endPos[0] = i;
            } else if (stPos[1] == -1 && tree[i] != tree[stPos[0]]) {
                stPos[1] = i;
                endPos[1] = i;
            } else if (tree[i] == tree[stPos[1]]) {
                endPos[1] = i;
            } else {
                res = max(res, i - stPos[0]);
                stPos[0] = min(endPos[0] + 1, endPos[1] + 1);
                endPos[0] = i - 1;
                if (stPos[0] < i) {
                    stPos[1] = i;
                    endPos[1] = i;
                } else {
                    stPos[1] = -1;
                    endPos[1] = -1;
                }
            }
        }
        res = max(res, len - stPos[0]);
        return res;
    }
};
