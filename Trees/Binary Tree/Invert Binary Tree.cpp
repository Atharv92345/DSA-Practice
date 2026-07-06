//Leetcode 226 - Invert Binary Tree
//https://leetcode.com/problems/invert-binary-tree/description/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return root;
       invertTree(root->right);
       invertTree(root->left);
       swap(root->right, root->left);
       return root;
    }
};
