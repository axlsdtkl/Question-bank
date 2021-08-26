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
    void reorderList(ListNode* head) {
        if(head==NULL)return;
        stack<ListNode*>S;
        ListNode* root=head;
        int cnt=0;
        while(root!=NULL){
            cnt++;
            S.push(root);
            root=root->next;
        }
        ListNode* h=head;
        ListNode* now=head->next;
        if(now==NULL)return;
        for(int i=2;i<=cnt;i++){
            if(i%2==0){
                h->next=S.top();
                S.pop();
                h=h->next;
            }else{
                h->next=now;
                h=h->next;
                now=now->next;
            }
        }
        h->next=NULL;
        return;
    }
};