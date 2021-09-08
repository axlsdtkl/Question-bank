/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* L2H=list2;
        ListNode* L2T=L2H;
        while(L2T->next!=NULL)L2T=L2T->next;
        int id=0;
        ListNode* now=list1;
        ListNode* mark1;
        ListNode* mark2;
        for(;;){
            if(id==a-1)mark1=now;
            if(id==b+1)mark2=now;
            id++;
            now=now->next;
            if(now==NULL)break;
        }
        mark1->next=L2H;
        L2T->next=mark2;
        return list1;
    }
};