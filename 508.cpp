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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        int mysum = sum(root);
        itr = maps.find(mysum);
        if (itr == maps.end()) maps.insert(pair<int, int>(mysum, 1));
        else itr->second++;
        int maxn = 0;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second > maxn) {
                maxn = itr->second;
                res.clear();
                res.push_back(itr->first);
            } else if (itr->second == maxn) {
                res.push_back(itr->first);
            }
        }
        return res;
    }

    int sum(TreeNode *root) {
        int left = 0, right = 0;
        if (root->left != NULL) {
            left = sum(root->left);
            itr = maps.find(left);
            if (itr == maps.end()) maps.insert(pair<int, int>(left, 1));
            else itr->second++;
        }
        if (root->right != NULL) {
            right = sum(root->right);
            itr = maps.find(right);
            if (itr == maps.end()) maps.insert(pair<int, int>(right, 1));
            else itr->second++;
        }
        int mysum = left + right + root->val;
        
        return mysum;
    }

private:
    map<int, int> maps;
    map<int, int>::iterator itr;
};
