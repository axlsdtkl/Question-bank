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
    bool hasCycle(ListNode *head) {
        for(int i=1;i<=20000;i++){
            if(head==NULL){
                return false;
            }
            head=head->next;
        }
        return true;
    }
};