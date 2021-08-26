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
    ListNode* Q[110000];
    int cnt=0;
    bool isPalindrome(ListNode* head) {
        while(head){
            cnt++;
            Q[cnt]=head;
            head=head->next;
        }
        for(int i=1;i<=cnt/2;i++){
            if(Q[i]->val!=Q[cnt-i+1]->val)return false;
        }
        return true;
    }
};