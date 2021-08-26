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
    ListNode* a[110000];
    static int cmp(ListNode* x,ListNode* y){
        if(x->val<y->val)return 1;
        return 0;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return head;
        int n=0;
        while(head!=NULL){
            n++;
            a[n]=head;
            head=head->next;
        }
        sort(a+1,a+n+1,cmp);
        ListNode* root=a[1];
        ListNode* now=root;
        for(int i=2;i<=n;i++){
            now->next=a[i];
            now=now->next;
        }
        now->next=NULL;
        return root;
    }
};