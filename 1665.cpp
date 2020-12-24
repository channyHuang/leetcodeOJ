class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {       
        sort(tasks.begin(), tasks.end(), cmp);
        int res = tasks[0][1];
        for (int i = 1; i < tasks.size(); i++) {
            res += tasks[i][0];
            if (res < tasks[i][1]) {
                res = tasks[i][1];
            }
        }
        return res;
    }

    static int cmp(vector<int>& a, vector<int>& b) {
        if (a[1] - a[0] == b[1] - b[0]) {
            return a[1] < b[1];
        }
        return a[1] - a[0] < b[1] - b[0];
    }
};
