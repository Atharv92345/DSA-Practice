//Leetcode 669 - Trim a Binary Search Tree
//https://leetcode.com/problems/trim-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return root;
        }
        if(root->val <= high){
            root->right = trimBST(root->right, low, high);
        }else{
            TreeNode* temp = root->left;
            return trimBST(temp, low, high);

        }
        if(root->val >= low){
            root->left = trimBST(root->left, low, high);
        }else{
            TreeNode* temp = root-> right;
            return trimBST(temp, low, high);
        }
        return root;
    }
};
