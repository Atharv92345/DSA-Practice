//Leetcode 236 - Lowest Common Ancestor of a Binary Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* lefta = lowestCommonAncestor(root->left, p, q);
        TreeNode* righta = lowestCommonAncestor(root->right, p, q);
        
        if(lefta != NULL && righta != NULL){
            return root;
        }

        if(righta == NULL){
            return lefta;
        }else{
            return righta;
        }
    }
};
