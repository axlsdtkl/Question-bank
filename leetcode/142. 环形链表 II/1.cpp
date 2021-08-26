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
        map<ListNode*,int>M;
        while(head){
            if(M.count(head)==1)return head;
            M[head]=1;
            head=head->next;
        }
        return NULL;
    }
};