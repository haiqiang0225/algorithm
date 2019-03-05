/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        if (root == NULL) return 0;
        int ldeep = maxDepth(root->left);
        int rdeep = maxDepth(root->right);
        return max(ldeep, rdeep) + 1;
    }
};
