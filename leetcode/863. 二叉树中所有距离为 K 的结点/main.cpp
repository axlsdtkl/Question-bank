/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>e[1000];
    vector<int>ans;
    int flag[1000];
    void add(int x,int y){
        e[x].push_back(y);
    }
    void dfs(TreeNode* now){
        if(now->left!=NULL){
            TreeNode* l=now->left;
            add(now->val,l->val);
            add(l->val,now->val);
            dfs(l);
        }
        if(now->right!=NULL){
            TreeNode* r=now->right;
            add(now->val,r->val);
            add(r->val,now->val);
            dfs(r);
        }
    }
    void dfs1(int x,int k){
        if(flag[x]==1)return;
        flag[x]=1;
        if(k==0){
            ans.push_back(x);
            return;
        }
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i];
            dfs1(y,k-1);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        dfs1(target->val,k);
        return ans;
    }
};
