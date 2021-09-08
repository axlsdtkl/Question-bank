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
    struct data{
        int val,id;
        bool operator<(const data &up)const{
            return val>up.val;
        }
    };
    priority_queue<data>q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode();
        ListNode* tail=head;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)q.push({lists[i]->val,i});
        }
        ListNode* temp;
        bool flag=0;
        while(q.size()){
            flag=1;
            data now=q.top();
            q.pop();
            tail->val=now.val;
            ListNode* po=new ListNode();
            tail->next=po;
            temp=tail;
            tail=po;
            lists[now.id]=lists[now.id]->next;
            if(lists[now.id]!=NULL){
                q.push({lists[now.id]->val,now.id});
            }
        }
        if(flag==0)return NULL;
        temp->next=NULL;
        return head;
    }
};