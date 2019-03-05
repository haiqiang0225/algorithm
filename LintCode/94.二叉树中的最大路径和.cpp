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
    int maxPath(TreeNode *node, int &curMax) {
        if (node == NULL) return 0;
        int lmax = maxPath(node->left, curMax);
        int rmax = maxPath(node->right, curMax);
        curMax = max(curMax, max(0, lmax)+max(0, rmax)+node->val);
        return max(0, max(lmax,rmax)+node->val);
    }
    
    int maxPathSum(TreeNode * root) {
        if (root == NULL) return 0;
        int max = INT_MIN;
        maxPath(root, max);
        return max;
    }
};
