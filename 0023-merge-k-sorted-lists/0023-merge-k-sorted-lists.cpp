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
    ListNode* merge(ListNode *l,ListNode *r){
        ListNode *res=new ListNode(0);
        ListNode* p=res;
        while(l && r){
            if(l->val < r->val){
                p->next=l;
                l=l->next;
            }
            else{
                p->next=r;
                r=r->next;
            }
            p=p->next;
        }
        if(l) p->next=l;
        if(r) p->next=r;
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& a) {
        if(a.size()==0) return NULL;
        ListNode *res=a[0];
        for(int i=1;i<a.size();i++){
            res=merge(res,a[i]);
        }
        return res;
    }

};