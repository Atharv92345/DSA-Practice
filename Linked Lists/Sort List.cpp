//Leetcode 148 - Sort List
//https://leetcode.com/problems/sort-list/description/

class Solution {
public:
    ListNode* merge(ListNode* head, ListNode* head2){
        ListNode* temp = head;
        ListNode* temp2 = head2;
        ListNode dummy(0);
        ListNode* ans = &dummy;
        while(temp != nullptr && temp2 != nullptr){
           if(temp->val > temp2->val){
             ans->next = temp2;
             temp2 = temp2->next;
           }else{
             ans->next = temp;
             temp = temp->next;
           }
           ans = ans->next;
        }
        while(temp != nullptr){
            ans->next = temp;
            temp = temp->next;
            ans = ans->next;
        }
        while(temp2 != nullptr){
            ans->next = temp2;
            temp2 = temp2->next;
            ans = ans->next;
        }
        return dummy.next;
     }

    ListNode* split(ListNode* head){
        ListNode* temp = head;
        ListNode* express = head;
        ListNode* prev = nullptr;
        while(express && express->next){
            prev = temp;
            temp = temp->next;
            express = express->next->next;
        }
        prev->next = nullptr;
        return temp;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* head2 = split(head);
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head, head2);
    }
};
