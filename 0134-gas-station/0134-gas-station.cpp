class Solution {
public:
    //time O(n)
    //space O(1)
    int canCompleteCircuit(vector<int>& a, vector<int>& b) {
        int total_gas=accumulate(a.begin(),a.end(),0);
        int total_cost=accumulate(b.begin(),b.end(),0);
        if(total_gas < total_cost) return -1;
        int res=0,n=a.size();
        int cur=0;
        //kadane
        for(int i=0;i<n;i++){
            cur+=a[i]-b[i];
            if(cur < 0){
                //starting point move to the next position
                res=i+1;
                cur=0; //reset
            }
        }
        return res;
    }
};