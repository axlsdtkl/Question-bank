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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* in,out;
        ListNode* root=head;
        if(left==right)return head;
        int cnt=0;
        ListNode* prev=NULL;
        while(head!=NULL){
            cnt++;
            if(cnt==left){
                in=prev;
                prev=head;
                head=head->next;
                continue;
            }
            if(cnt>left&&cnt<=right){
                ListNode* next=head->next;
                head->next=prev;
                prev=head;
                head=next;
                if(cnt==right){
                    if(left==1){
                        root->next=head;
                        return prev;
                    }
                    ListNode* temp=in->next;
                    in->next=prev;
                    temp->next=head;
                    return root;
                }
                continue;
            }
            prev=head;
            head=head->next;
        }
        return root;
    }
};