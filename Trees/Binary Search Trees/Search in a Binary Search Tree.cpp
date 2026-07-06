//Leetcode 700 - Search in a Binary Search Tree
//https://leetcode.com/problems/search-in-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
         if(root == NULL){
            return root;
         }
         while(root != NULL && root->val != val){
            if(root->val < val){
                root = root->right;
            }else{
                root = root->left;
            }
         }
         return root;
    }
};
