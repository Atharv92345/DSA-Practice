//Leetcode 142 - Linked List Cycle II
//https://leetcode.com/problems/linked-list-cycle-ii/description/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* temp = head;
        ListNode* Express = head;
        while(Express->next != nullptr && Express->next->next != nullptr){
            temp = temp->next;
            Express = Express->next->next;
            if(temp == Express){
                temp = temp->next;
                while(temp > Express){
                    temp = temp->next;
                }
                return temp;
            }
        }
        return nullptr;
    }
};
