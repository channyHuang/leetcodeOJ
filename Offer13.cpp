// 一开始以为是求所有坐标位数和不大于k的位置，然后直接WA了。。。
// 题目的意思是不但坐标位数和不大于k，而且从初始位置(0,0)能够通过上下左右移动过去而不用跳跃的。即与原点连通的

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> used(m, vector<bool>(n, false));
        count = 0;
        search(0, 0, m, n, k, used);
        return count;
    }

    void search(int r, int c, int m, int n, int k, vector<vector<bool>> &used) {
        used[r][c] = true;
        count++;
        if (r > 0 && !used[r - 1][c] && (calc(r - 1) + calc(c) <= k)) {
            search(r - 1, c, m, n, k, used);
        }
        if (r < m - 1 && !used[r + 1][c] && (calc(r + 1) + calc(c) <= k)) {
            search(r + 1, c, m, n, k, used);
        }
        if (c > 0 && !used[r][c - 1] && (calc(r) + calc(c - 1) <= k)) {
            search(r, c - 1, m, n, k, used);
        }
        if (c < n - 1 && !used[r][c + 1] && (calc(r) + calc(c + 1) <= k)) {
            search(r, c + 1, m, n, k, used);
        }
    }

    int calc(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

private:
    int count = 0;
};


// WA
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int count = 0;
        for (int i = 0; i < m; ++i) {
            int target = k - calc(i);
            for (int j = 0; j < n; ++j) {
                if (calc(j) <= target) count++;
            }
        }
        return count;
    }

    int calc(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
};
