class Solution {
public:
    //time O(nlogn)
    //space O(n)
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        priority_queue<pair<int,int>> q; //max heap to get the largest element as a multiply factor
        priority_queue<int,vector<int>,greater<int>> q1; //min heap to store only max value within k size
        for(int i=0;i<b.size();i++){
            q.push({b[i],a[i]});
        }
        long long sum=0;
        long long res=0;
        while(q.size()){
            int val=q.top().second;
            int multi_factor=q.top().first; // after k element the factor is itself because of min among k size
            q.pop();
            sum+=val;
            q1.push(val);
            if(q1.size()>k){
                sum-=q1.top(); //pop the smallest element to always fetch the maximum score
                q1.pop();
            }
            if(q1.size()==k){
                res=max(res,sum*multi_factor);
            }

        }
        return res;
    }
};