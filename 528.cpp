class Solution {
public:
    vector<int> weight;
    int total;

    Solution(vector<int>& w) {
        if (w.size() <= 0) return;
        total = w[0];
        weight.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) {
            total += w[i];
            weight.push_back(weight[i - 1] + w[i]);
        }
    }
    
    int pickIndex() {
        int tmp = rand() % total;
        for (int i = 0; i < weight.size(); i++) {
            if (tmp < weight[i]) return i;
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
