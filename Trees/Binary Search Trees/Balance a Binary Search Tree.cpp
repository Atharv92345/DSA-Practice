//Leetcode 1382 - Balance a Binary Search Tree
//https://leetcode.com/problems/balance-a-binary-search-tree/description/

class Solution {
public:
    void Inorder(TreeNode* root, vector<int>& traversal){
        if(root == NULL){
            return;
        }
        Inorder(root->left, traversal);
        traversal.push_back(root->val);
        Inorder(root->right, traversal);
    }

    TreeNode* bulid(vector<int>& traversal, int s, int e){
        if(s > e){
            return NULL;
        }
        int mid = s + ((e-s)/2);
        TreeNode* z = new TreeNode (traversal[mid]);
        z->left = bulid(traversal, s, mid-1);
        z->right = bulid(traversal, mid+1, e);
        return z;
    }

    TreeNode* balanceBST(TreeNode* root) {
     if(root == NULL){
        return root;
     }
     vector<int> traversal;
     Inorder(root, traversal);
     return bulid(traversal, 0, traversal.size() - 1);
    }
};
