/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(1){
            if(fast==NULL)return NULL;
            fast=fast->next;
            if(fast==NULL)return NULL;
            fast=fast->next;
            slow=slow->next;
            if(fast==NULL)return NULL;
            if(fast==slow)break;
        }
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        return head;
    }
};