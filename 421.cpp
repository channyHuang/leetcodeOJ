class Solution {
public:
    class Node {
    public:
        bool bit;
        Node *child[2];
        bool isend;
        int val;
        Node (bool _bit = false) {
            bit = _bit;
            child[0] = NULL;
            child[1] = NULL;
            isend = false;
            val = 0;
        }
    };
    Node *root;

    int findMaximumXOR(vector<int>& nums) {
        int len = nums.size();
        root = new Node();
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            for (int j = 31; j >= 0; j--) {
                int tmp = ((nums[i] >> j) & 1);
                if (curNode->child[tmp] == NULL) curNode->child[tmp] = new Node(tmp);
                curNode = curNode->child[tmp];
            }
            curNode->isend = true;
            curNode->val = nums[i];
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            int subres = 0;
            int j;
            for (j = 31; j >= 0; j--) {
                if (nums[i] & (1 << j)) {
                    if (curNode->child[0]) {
                        curNode = curNode->child[0];
                        subres += (1 << j);
                    } else if (curNode->child[1]) {
                        curNode = curNode->child[1];
                    } else break;
                } else {
                    if (curNode->child[1]) {
                        curNode = curNode->child[1];
                        subres += (1 << j);
                    } else if (curNode->child[0]) {
                        curNode = curNode->child[0];
                    } else break;
                }
            }
            if (j < 0 && curNode->isend)
                if (res < subres) res = subres;
        }
        return res;
    }
};
