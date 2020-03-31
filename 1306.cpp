class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        if (len == 1) return true;
        bool used[len];
        memset(used, 0, sizeof(used));
        queue<int> index;
        index.push(start);
        while (!index.empty()) {
            int idx = index.front();
            index.pop();
            if (used[idx]) continue;
            used[idx] = true;
            int next = idx + arr[idx];
            int pre = idx - arr[idx];
            if (next < len) {
                if (arr[next] == 0) return true;
                else if (!used[next]) index.push(next);
            } 
            if (pre >= 0) {
                if (arr[pre] == 0) return true;
                else if (!used[pre]) index.push(pre);
            }
        }
        return false;
    }
};
