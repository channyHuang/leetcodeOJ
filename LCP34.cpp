// 树形dp

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
    struct DpNode {
        vector<int> dp;
        DpNode *left;
        DpNode *right;
        DpNode() : left(nullptr), right(nullptr) {}
    };

    int maxValue(TreeNode* root, int k) {
        if (root == nullptr) return 0;
        DpNode *dproot = new DpNode();
        search(root, k, dproot);
        int res = dproot->dp[0];
        for (int i = 1; i < (int)dproot->dp.size(); ++i) {
            res = std::max(res, dproot->dp[i]);
        }
        return res;
    }

    void search(TreeNode *root, int k, DpNode *dproot) {
        if (root == nullptr) return;
        dproot->dp.push_back(0);
        dproot->dp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            //output(root, dproot);
            return;
        }
        if (root->left == nullptr) {
            dproot->right = new DpNode();
            search(root->right, k, dproot->right);
            for (int i = 0; i < (int)dproot->right->dp.size(); ++i) {
                dproot->dp[0] = std::max(dproot->dp[0], dproot->right->dp[i]);
            }
            dproot->dp[1] = std::max(dproot->dp[1], dproot->right->dp[0] + root->val);
            int maxn = std::min(k, (int)dproot->right->dp.size());
            for (int i = 2; i <= maxn; ++i) {
                dproot->dp.push_back(dproot->right->dp[i - 1] + root->val);
            }
            //output(root, dproot);
            return;
        }
        if (root->right == nullptr) {
            dproot->left = new DpNode();
            search(root->left, k, dproot->left);
            for (int i = 0; i < (int)dproot->left->dp.size(); ++i) {
                dproot->dp[0] = std::max(dproot->dp[0], dproot->left->dp[i]);
            }
            dproot->dp[1] = std::max(dproot->dp[1], dproot->left->dp[0] + root->val);
            int maxn = std::min(k, (int)dproot->left->dp.size());
            for (int i = 2; i <= maxn; ++i) {
                dproot->dp.push_back(dproot->left->dp[i - 1] + root->val);
            }
            //output(root, dproot);
            return;
        }
        dproot->right = new DpNode();
        search(root->right, k, dproot->right);
        dproot->left = new DpNode();
        search(root->left, k, dproot->left);

        int maxn = std::min(k, (int)dproot->left->dp.size() + (int)dproot->right->dp.size() - 1);
        dproot->dp.resize(maxn + 1, 0);
        for (int i = 0; i < dproot->left->dp.size(); ++i) {
            if (i + 1 <= maxn) {
                dproot->dp[i + 1] = std::max(dproot->dp[i + 1], dproot->left->dp[i] + root->val + dproot->right->dp[0]);
            }
            for (int j = 0; j < dproot->right->dp.size(); ++j) {
                if (j + 1 <= maxn) {
                    dproot->dp[j + 1] = std::max(dproot->dp[j + 1], dproot->right->dp[j] + root->val + dproot->left->dp[0]);
                }
                dproot->dp[0] = std::max(dproot->dp[0], dproot->left->dp[i] + dproot->right->dp[j]);
                if (i + j + 1 <= maxn) {
                    dproot->dp[i + j + 1] = std::max(dproot->dp[i + j + 1], dproot->left->dp[i] + dproot->right->dp[j] + root->val);
                }
            }
        }
        //output(root, dproot);
    }

    void output(TreeNode *root, DpNode *node) {
        cout << root->val << ": " << endl;
        for (int i = 0; i < node->dp.size(); ++i) {
            cout << node->dp[i] << " ";
        }
        cout << endl;
    }
};
