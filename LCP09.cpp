class Solution {
public:
    int minJump(vector<int>& jump) {
        int len = jump.size();
        if (len <= 1 || jump[0] >= len) return 1;
        vector<int> count(len, INT_MAX);
        queue<int> qu;
        qu.push(jump[0]);
        count[0] = 0;
        count[jump[0]] = 1;
        int minIdx = 1;
        while (!qu.empty()) {
            int curIdx = qu.front();
            qu.pop();
            //cout << curIdx << " " << count[curIdx] << endl;
            if (curIdx + jump[curIdx] >= len) {
                return count[curIdx] + 1;
            }
            if (count[curIdx + jump[curIdx]] > count[curIdx] + 1) {
                count[curIdx + jump[curIdx]] = count[curIdx] + 1;
                qu.push(curIdx + jump[curIdx]);
            }
            for (; minIdx < curIdx; minIdx++) {
                if (count[minIdx] > count[curIdx] + 1) {
                    count[minIdx] = count[curIdx] + 1;
                    qu.push(minIdx);
                }
            }
        }
        return -1;
    }
};
