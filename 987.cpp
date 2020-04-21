/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    class Node {
    public:
        int r; 
        int c;
        int val;
        Node (int _val = 0, int _r = 0, int _c = 0) {
            val = _val;
            r = _r;
            c = _c;
        }
    };

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<Node> nodes;
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<pair<TreeNode *, pair<int, int>>> qu;
        qu.push(pair<TreeNode *, pair<int, int>>(root, pair<int, int>(0, 0)));
        while (!qu.empty()) {
            pair<TreeNode *, pair<int, int>> curPair  = qu.front();
            qu.pop();
            nodes.push_back(Node(curPair.first->val, curPair.second.first, curPair.second.second));
            if (curPair.first->left ) {
                qu.push(pair<TreeNode *, pair<int, int>>(curPair.first->left, pair<int, int>(curPair.second.first - 1, curPair.second.second - 1)));
            }
            if (curPair.first->right ) {
                qu.push(pair<TreeNode *, pair<int, int>>(curPair.first->right, pair<int, int>(curPair.second.first + 1, curPair.second.second - 1)));
            }
        }
        sort(nodes.begin(), nodes.end(), cmp);
        int lastX = nodes[0].r - 1;
        int pos = -1;
        for (int i = 0; i < nodes.size(); i++) {
            if (lastX == nodes[i].r) {
                res[pos].push_back(nodes[i].val);
            } else {
                lastX = nodes[i].r;
                vector<int> sub;
                sub.push_back(nodes[i].val);
                res.push_back(sub);
                pos++;
            }
        }
        return res;
    }

    static bool cmp(Node& a, Node& b) {
        if (a.r == b.r && a.c == b.c) return a.val < b.val;
        if (a.r == b.r) return a.c > b.c;
        return a.r < b.r;
    }
};
