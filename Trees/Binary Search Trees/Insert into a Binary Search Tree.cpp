//Leetcode 701 - Insert into a Binary Search Tree
//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode (val);
        }
        if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }else{
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};
