//Leetcode 103 - Binary Tree Zigzag Level Order Traversal
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> a;
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
        }
        bool f = false;
        while(!q.empty()){
           vector<int> b;
           int size = q.size();
           for(int i = 0; i < size; i++){
               TreeNode* c = q.front();
               q.pop();
               int d = c->val;
               b.push_back(d);
               TreeNode* l = c->left;
               TreeNode* r = c->right;
               if(l != NULL){
                  q.push(l);
               }
               if(r != NULL){
                  q.push(r);
               }
           }    
           if(f){
             reverse(b.begin(), b.end());
           }
           a.push_back(b);
           f = !f;
        }
        return a;
    }
};
