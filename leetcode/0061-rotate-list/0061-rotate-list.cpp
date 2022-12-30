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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        int len=1;
        ListNode* tail=head,*newhead=head;
        //calculate length of linked list
        while(tail->next){
            len++;
            tail=tail->next;
        }
        //circle the linked list
        tail->next=head;
        
        //find start and end of rotate
        if(k%=len){
            for(int i=0;i<len-k;i++){
                tail=tail->next;
            }
        }
        newhead=tail->next;
        tail->next=NULL;
        return newhead;
    }
};