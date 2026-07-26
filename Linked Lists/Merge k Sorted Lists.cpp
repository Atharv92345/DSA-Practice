//Leetcode 23 - Merge k Sorted Lists
//https://leetcode.com/problems/merge-k-sorted-lists/description/

class Solution {
public:
    ListNode* merge(ListNode* traverse, ListNode* head2){
        ListNode* temp1 = traverse;
        ListNode* temp2 = head2;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while(temp1 && temp2){
            if(temp1->val > temp2->val){
                ans->next = temp2;
                temp2 = temp2->next;
            }else{
                ans->next = temp1;
                temp1 = temp1->next;
            }
            ans = ans->next;
        }
        while(temp1){
            ans->next = temp1;
            ans = ans->next;
            temp1 = temp1->next;
        }
        while(temp2){
            ans->next = temp2;
            ans = ans->next;
            temp2 = temp2->next;
        }
        return dummy->next;
    }

    ListNode* split(ListNode* traverse){
          ListNode* temp = traverse;
          ListNode* fast = traverse;
          ListNode* prev = nullptr;
          while(fast && fast->next){  
            prev = temp;
            temp = temp->next;
            fast = fast->next->next;
          }
          prev->next = nullptr;
          return temp;
     }

    ListNode* sort(ListNode* traverse){
        if(traverse == nullptr || traverse->next == nullptr){
            return traverse;
        }
        ListNode* head2 = split(traverse);
        traverse = sort(traverse);
        head2 = sort(head2);
        return merge(traverse, head2); 
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        ListNode* traverse = new ListNode(0);
        ListNode* end = traverse;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){
               while(end->next != nullptr){
                  end = end->next;
               }
               end->next = lists[i];
            }
        }
        return sort(traverse->next);
    } 
};
