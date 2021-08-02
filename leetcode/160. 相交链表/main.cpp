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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)return NULL;
        ListNode *nowA=headA,*nowB=headB;
        while(nowA!=nowB){
            if(nowA==NULL)nowA=headB;else nowA=nowA->next;
            if(nowB==NULL)nowB=headA;else nowB=nowB->next;
        }
        return nowA;
    }
};