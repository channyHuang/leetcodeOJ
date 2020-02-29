class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> rev;
        while (label) {
            rev.push_back(label);
            label /= 2;
        }
        int len = rev.size();
        for (int i = 0; i < len / 2; i++) {
            int tmp = rev[i];
            rev[i] = rev[len - i - 1];
            rev[len - i - 1] = tmp;
        }
        for (int i = 1; i < len - 1; i++) {
            if ((i & 1) == (len & 1)) {
                int level = i + 1;
                int stPos = pow(2, i);
                int endPos = pow(2, level) - 1;
                rev[i] = endPos + stPos - rev[i];
            }
        }
        
        return rev;
    }
};
