//Leetcode 100 - Same Tree
//https://leetcode.com/problems/same-tree/description/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if((p != NULL && q == NULL)||(p == NULL && q != NULL)){
            return false;
        }
        if(p->val != q->val) return false;
        bool a = isSameTree(p->right, q->right);
        bool b = isSameTree(p->left, q->left);   
        if(!a || !b){
            return false;
        }
        return true;
    }
};
