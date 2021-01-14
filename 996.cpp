class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        len = A.size();
        sort(A.begin(), A.end());
        edges.resize(len, vector<int>());

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int sum = A[i] + A[j];
                int factor = sqrt(sum);
                if (factor * factor == sum) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        vector<bool> used(len, false);
        for (int i = 0; i < len; i++) {
            if (i > 0 && A[i] == A[i - 1]) continue;
            used[i] = true;
            dfs(A, used, 1, i);
            used[i] = false;
        }
        return res;
    }

    void dfs(vector<int>& A, vector<bool> used, int count, int lastIndex) {
        if (count >= len) {
            res++;
            return;
        }
        int last = -1;
        for (int i = 0; i < edges[lastIndex].size(); i++) {
            if (used[edges[lastIndex][i]]) continue;
            if (last >= 0 && A[edges[lastIndex][i]] == A[last]) continue;
            used[edges[lastIndex][i]] = true;
            dfs(A, used, count + 1, edges[lastIndex][i]);
            used[edges[lastIndex][i]] = false;
            last = edges[lastIndex][i];
        }
    }

private:
    int len;
    vector<vector<int>> edges;
    int res = 0;
};
