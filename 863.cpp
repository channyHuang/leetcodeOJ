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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        if (root == NULL) return res;
        if (K == 0) {
            res.push_back(target->val);
            return res;
        }      
        vector<TreeNode *> vec;
        vec.push_back(root);
        int pos = 1;
        flag = false;
        search(target, vec, pos);
        for (int i = pos - 1; i >= 0; i--) {
            vector<int> sub = childrenK(vec[i], K);
            if (i > 0 && vec[i - 1]->left == vec[i]) {
                vec[i - 1]->left = NULL;
            }
            if (i > 0 && vec[i - 1]->right == vec[i]) {
                vec[i - 1]->right = NULL;
            }
            K--;
            for (int i = 0; i < sub.size(); i++) res.push_back(sub[i]);
            if (K < 0) break;
        }
        return res;
    }

    void search(TreeNode* target, vector<TreeNode *>& vec, int& pos) {
        if (flag) return;
        if (vec[pos - 1] == target) {
            flag = true;
            return;
        }
        if (vec[pos - 1]->left != NULL) {
            if (vec.size() > pos) vec[pos] = vec[pos - 1]->left;
            else vec.push_back(vec[pos - 1]->left);
            search(target, vec, ++pos);
            if (flag) return;
            --pos;
        }
        if (vec[pos - 1]->right != NULL) {
            if (vec.size() > pos) vec[pos] = vec[pos - 1]->right;
            else vec.push_back(vec[pos - 1]->right);
            search(target, vec, ++pos);
            if (flag) return;
            --pos;
        }
    }

    vector<int> childrenK(TreeNode* target, int K) {
        vector<int> res;
        if (K == 0) {
            res.push_back(target->val);
            return res;
        }

        queue<pair<TreeNode *, int>> qu;
        qu.push(pair<TreeNode *, int>(target, 0));
        while (!qu.empty()) {
            pair<TreeNode *, int> curPair = qu.front();
            qu.pop();
            if (curPair.first->left != NULL) {
                if (curPair.second + 1 == K) {
                    res.push_back(curPair.first->left->val);
                } else {
                    qu.push(pair<TreeNode *, int>(curPair.first->left, curPair.second + 1));
                }
            }
            if (curPair.first->right != NULL) {
                if (curPair.second + 1 == K) {
                    res.push_back(curPair.first->right->val);
                } else {
                    qu.push(pair<TreeNode *, int>(curPair.first->right, curPair.second + 1));
                }
            }
        }

        return res;
    }

private:
    bool flag;
};
