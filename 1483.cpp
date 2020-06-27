class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < n; i++) {
            vector<int> vec;
            vec.push_back(parent[i]);
            dp.push_back(vec);
        }

        bool needContinue = true;
        while (needContinue) {
            needContinue = false;
            int len = dp[0].size();
            for (int i = 0; i < n; i++) {
                if (dp[i][len - 1] == -1) {
                    dp[i].push_back(-1);
                    continue;
                }
                int pa = dp[dp[i][len - 1]][len - 1];
                dp[i].push_back(pa);
                if (pa != -1) needContinue = true;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (node == -1 || k == 0) return node;
        int pos = 0;
        while ((k & (1 << pos)) == 0) {
            pos++;
            if (pos >= dp[node].size()) return -1;
        }
        //std::cout << node << " " << k << " " << pos << std::endl;
        return getKthAncestor(dp[node][pos], k - (1 << pos));
    }

private:
    vector<vector<int>> dp;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */