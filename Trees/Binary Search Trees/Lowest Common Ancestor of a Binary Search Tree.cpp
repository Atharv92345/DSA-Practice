//Leetcode 235 - Lowest Common Ancestor of a Binary Search Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(p->val > root->val && q->val > root->val){
             return lowestCommonAncestor(root->right, p, q);
        }else if(p->val < root->val && q->val < root->val){
             return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
