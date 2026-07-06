//Leetcode 98 - Validate Binary Search Tree
//https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
      if(root == NULL){
        return true;
      }
      queue<pair<TreeNode*, pair<long long, long long >>> q;
      q.push({root, {LLONG_MIN, LLONG_MAX}});
      while(!q.empty()){
           pair<TreeNode*, pair<long long, long long>> p = q.front();
           TreeNode* a = p.first;
           long long cmi = p.second.first;
           long long cm = p.second.second;
           q.pop();
           TreeNode* l = a->left;
           TreeNode* r = a->right;
           if(l != NULL){ 
              long long m = a->val;
              if(cmi >= l->val || m <= l->val){
                return false;
              }
              q.push({l, {cmi, m}});
           }
           if(r != NULL){
              long long mi = a->val;
              if(mi >= r->val || cm <= r->val){
                return false;
              }
              q.push({r, {mi, cm}});
           }
      }
      return true;
    }
};
