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
    //time O(n)
    //space O(1)
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        ListNode* p=head;

        int length=0;
        while(p){
            length++;
            p=p->next;
        }
        //every idx contains times size
        int times=length/k;
        //redundant added to earlier index
        int redundant= length%k;

        p=head;
        int i=0;
        while(p){
            int each=times;
            if(redundant-->0)
                each++;
            ListNode* start=p;
            for(int j=0;j<each-1;j++){
                p=p->next;
            }
            ListNode* nxt=p->next;
            p->next=NULL;
            p=nxt;
            res[i]=start;
            i++;
        }
        return res;
    }
};