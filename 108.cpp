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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() <= 0) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);

        return buildSubTree(nums, 0, nums.size() - 1);
    }

    TreeNode *buildSubTree(vector<int> & nums, int stPos, int endPos) {
        if (stPos == endPos) return new TreeNode(nums[stPos]);
        if (stPos > endPos) return NULL;
        int midPos = (stPos + endPos) / 2;
        TreeNode *res = new TreeNode(nums[midPos]);
        res->left = buildSubTree(nums, stPos, midPos - 1);
        res->right = buildSubTree(nums, midPos + 1, endPos);
        return res;
    }

    
};
