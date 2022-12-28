class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        priority_queue<int> q(a.begin(),a.end()); //max heap
        int res=accumulate(a.begin(),a.end(),0);//total sum
        while(k--){
            int top=q.top();
            q.pop();
            q.push(top-top/2); //floor
            res-=top/2;
        }
        return res;
    }
};