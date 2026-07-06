//Leetcode 110 - Balanced Binary Tree
//https://leetcode.com/problems/balanced-binary-tree/description/

class Solution {
public:
    int depth(TreeNode* root){
       if(root == NULL){
        return 0;
       }
       int l = depth(root->left);
       if(l == -1){
        return -1;
       }
       int r = depth(root->right);
       if(r == -1){
        return -1;
       }
       int check = abs(l-r);
       if(check != 0 && check != 1){
          return -1;
       }
       return max(l,r) + 1;
    }

    bool isBalanced(TreeNode* root) {
       if(depth(root) != -1){
        return true;
       }      
       return false;
    }
};
