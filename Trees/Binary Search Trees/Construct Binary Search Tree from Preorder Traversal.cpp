//Leetcode 1008 - Construct Binary Search Tree from Preorder Traversal
//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

class Solution {
public:
    TreeNode* Insert(TreeNode* root, int val){
          if(root == NULL){
            return new TreeNode (val);
          }
          if(root->val < val){
            root->right = Insert(root->right, val);
          }else{
            root->left = Insert(root->left, val);
          }
          return root;
    }
 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;       
        if(preorder.size() <= 0){
            return root;
        }
        root = new TreeNode (preorder.front());
        for(int i = 1; i < preorder.size(); i++){
            int val = preorder[i];
            root = Insert(root, val);
        }
        return root;
    }
};
