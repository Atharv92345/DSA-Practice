//GeeksforGeeks - Predecessor and Successor
//https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* temp = root;
        Node* a = NULL;
        Node* b = NULL;
        while(root != NULL){
            if(key < root->data){
                a = root;
                root = root->left;
                continue;
            }
            if(key >= root-> data){
                root = root->right;
            }
        }
        while(temp != NULL){
            if(key > temp->data){
                b = temp;
                temp = temp->right;
                continue;
            }else{
                temp = temp->left;
            }
        }
        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }
};
