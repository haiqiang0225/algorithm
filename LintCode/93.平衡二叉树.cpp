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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        if (root == NULL) return true;
        int ldeep = deep(root->left);
        int rdeep = deep(root->right);
        if (abs(ldeep - rdeep) <= 1) {
            return isBalanced(root->left) && isBalanced(root->right);
        } else {
            return false;
        }
    }
    
    int deep(TreeNode *root) {
        if (root == NULL)
            return 0;
        int ldeep = deep(root->left);
        int rdeep = deep(root->right);
        return max(ldeep, rdeep) + 1;
    }
};
