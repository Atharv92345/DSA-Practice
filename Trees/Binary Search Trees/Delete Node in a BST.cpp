//Leetcode 450 - Delete Node in a BST
//https://leetcode.com/problems/delete-node-in-a-bst/description/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
         if(root->right == NULL){
            TreeNode* Temp = root->left;
            delete root;
            return Temp;
        }else if(root->left == NULL){
            TreeNode* Temp = root->right;
            delete root;
            return Temp;
        }
        TreeNode* Temp = root->left;
        while(Temp->right != NULL){
            Temp = Temp->right;
        }
        root->val = Temp->val;
        root->left = deleteNode(root->left, Temp->val);
        }
        return root;
    }
};
