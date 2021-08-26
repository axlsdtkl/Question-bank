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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode* root=new ListNode();
        ListNode* now=root;
        for(;;){
            if(l1==NULL&&l2==NULL)break;
            if((l1!=NULL)&&(l2==NULL||(l1->val<l2->val))){
                now->next=l1;
                l1=l1->next;
            }else{
                now->next=l2;
                l2=l2->next;
            }
            now=now->next;
        }
        root=root->next;
        return root;
    }
};