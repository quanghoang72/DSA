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
        if(!head) return;
        deque<int> d;
        ListNode* temp=head;
        while(temp){
            d.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int i=0;
        while(temp){
            if(i%2==0){temp->val=d.front();d.pop_front();}
            else {temp->val=d.back();d.pop_back();}
            temp=temp->next;
            i++;
        }
    }
};