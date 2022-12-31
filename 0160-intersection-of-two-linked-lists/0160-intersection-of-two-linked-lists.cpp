/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        ListNode *p1=h1;
        ListNode *p2=h2;
        if (p1 == NULL || p2 == NULL) return NULL;
        while(1){
            if(p1==p2) //intersection
                return p1;
            p1=p1->next;
            p2=p2->next;
            if(!p1 && !p2) return NULL;
            //if one of them reach null first (h1||h2 longer) make that pointer points to other one
            //to start over again the loop.
            //Once one of them are re-assigning, they are equidistant from collision point 
            if(!p1) p1=h2; 
            if(!p2) p2=h1; 
        }
        return p1;
    }
};