class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int incount[n] = {0};
        int outcount[n] = {0};
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                outcount[i]++;
                incount[leftChild[i]]++;
                if (incount[leftChild[i]] >= 2) return false;
            }
            if (rightChild[i] != -1) {
                outcount[i]++;
                incount[rightChild[i]]++;
                if (incount[rightChild[i]] >= 2) return false;
            }
        }
        bool hasroot = false;
        for (int i = 0; i < n; i++) {
            if (incount[i] == 0) {
                if (hasroot) return false;
                hasroot = true;
            }
        }
        return hasroot;
    }
};
