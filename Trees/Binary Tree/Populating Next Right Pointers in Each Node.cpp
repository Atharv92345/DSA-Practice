//Leetcode 116 - Populating Next Right Pointers in Each Node
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL){
            return root;
        }else{
            q.push(root);
        }
        Node* curr = root;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                curr = q.front();
                q.pop();
                Node* l = curr->left;
                Node* r = curr->right;
                if(l != NULL && r != NULL){
                    q.push(l);
                    q.push(r);
                }
                if(i<size-1){
                  curr->next = q.front();
                }
            }
        }
        return root;
    }
};
