//Leetcode 104 - Maximum Depth of Binary Tree
//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        TreeNode* current = root;
        TreeNode* c = root;
         if(current == NULL && c == NULL){
            return 0;
        }
        int RA = maxDepth(current->right);
        int LA = maxDepth(c->left);
        return max(RA, LA) + 1;
    }
};
