//GeeksforGeeks - Inorder Successor in BST
//https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
    
        if(root == NULL){
            return -1;
        }
        int suc = -1;
        while(root != NULL){
            if(root->data > k->data){
              suc = root->data;
              root = root->left;
              continue;
            }
            if(root->data <= k->data){
                root = root->right;
            }
        }
        return suc;
    }
};
