/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        startfound = false;
        endfound = false;
        startpath.clear();
        endpath.clear();
    
        vector<TreeNode*> path;
        dfs(root, path, 0, startValue, destValue);
        int slen = startpath.size();
        int elen = endpath.size();
        vector<char> direction(slen + elen, ' ');
        int stpos = 0, endpos = slen + elen - 1;
        int curst = slen - 1, curend = elen - 1;
        while (curst > curend) {
            direction[stpos++] = 'U';
            curst--;
        }
        while (curend > curst) {
            if (endpath[curend - 1]->left == endpath[curend])
               direction[endpos--] = 'L';
            else direction[endpos--] = 'R';
            curend--;
        }
        while (startpath[curst] != endpath[curend]) {
            direction[stpos++] = 'U';
            curst--;
            if (endpath[curend - 1]->left == endpath[curend])
               direction[endpos--] = 'L';
            else direction[endpos--] = 'R';
            curend--;
        }
        string res(stpos + slen + elen - 1 - endpos, ' ');
        int j = 0;
        for (int i = 0; i < direction.size(); ++i) {
            if (direction[i] == ' ') continue;
            res[j++] = direction[i]; 
        }
        
        return res;
    }

    void dfs(TreeNode *root, vector<TreeNode*> &path, int pos, int startValue, int destValue) {
        if (root == nullptr) return;
        if (pos >= path.size()) path.push_back(root);
        else path[pos] = root;
        if (root->val == startValue) {
            startfound = true;
            for (int i = 0; i <= pos; ++i) {
                startpath.push_back(path[i]);
            }
        }
        if (root->val == destValue) {
            endfound = true;
            for (int i = 0; i <= pos; ++i) {
                endpath.push_back(path[i]);
            }
        }
        if (startfound && endfound) return;
        dfs(root->left, path, pos + 1, startValue, destValue);
        if (startfound && endfound) return;
        dfs(root->right, path, pos + 1, startValue, destValue);
    }

private:
    vector<TreeNode *> startpath;
    vector<TreeNode *> endpath;
    bool startfound;
    bool endfound;
};
