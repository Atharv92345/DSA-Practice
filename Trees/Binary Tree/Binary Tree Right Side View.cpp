//Leetcode 199 - Binary Tree Right Side View
//https://leetcode.com/problems/binary-tree-right-side-view/description/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
          vector<int> a;
          queue<TreeNode*> q;
          if(root != NULL){
            q.push(root);
          }
          while(!q.empty()){
            int size = q.size();
            int c;
            for(int i = 0; i < size; i++){
                TreeNode* b = q.front();
                q.pop();
                c = b->val;
                TreeNode* r = b->right;
                TreeNode* l = b->left;
                if(l != NULL){
                    q.push(l);
                }
                if(r != NULL){
                    q.push(r);
                }
            }
            a.push_back(c);
          }
          return a;
    }
};
