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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        if (root == NULL) return true;
        bool isValid = true;
        long curMax = LONG_MIN;
        midForeach(root, isValid, curMax);
        return isValid;
    }
    void midForeach(TreeNode *root, bool &isValid, long &curMax) {
        if(root == NULL) return;
        midForeach(root->left, isValid, curMax);
        if(curMax >= root->val) {
            isValid = false;
        }
        curMax = root->val;
        midForeach(root->right, isValid, curMax);
    }
};
