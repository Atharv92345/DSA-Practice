//Leetcode 102 - Binary Tree Level Order Traversal
//https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> traversal;
        if(root == NULL){
            return traversal;
        }
        q.push(root);      
        while(!q.empty()){
             vector<int> level;
             int size = q.size();
             for(int i = 0; i < size; i++){
                TreeNode* a = q.front();
                q.pop();
                int b = a->val;
                level.push_back(b);
                TreeNode* r = a->right;
                TreeNode* l = a->left;
                if(l != NULL){
                    q.push(l);
                }
                if(r != NULL){
                    q.push(r);
                }
             }
             traversal.push_back(level);
        }
        return traversal;
    }
};
