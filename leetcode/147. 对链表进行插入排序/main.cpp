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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* root=new ListNode();
        root->val=head->val;
        head=head->next;
        while(head!=NULL){
            ListNode* prev=NULL;
            ListNode* now=root;
            while(now->val<head->val){
                prev=now;
                now=now->next;
                if(now==NULL)break;
            }
            if(prev==NULL){
                ListNode* temp=new ListNode();
                temp->val=head->val;
                temp->next=root;
                root=temp;
            }else{
                ListNode* temp=new ListNode();
                temp->next=now;
                temp->val=head->val;
                prev->next=temp;
            }
            head=head->next;
        }
        return root;
    }
};