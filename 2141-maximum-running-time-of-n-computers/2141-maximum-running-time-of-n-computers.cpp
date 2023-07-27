class Solution {
    typedef long long ll;
public:
    // time O(nlogk)
    // space O(1)
    // bs target hour comsumption from 1 to sum of batteries
    
    long long maxRunTime(int n, vector<int>& batteries) {
        ll total=0;
        for(auto b : batteries)
            total+=b;
    
        ll l=1,r=total;
        while(l<r){
            ll target=r-(r-l)/2;
            ll need=0;
            
            //total sum of batteries needed
            for(ll b : batteries)
                need+=min(b,target);
            
            if(need >= (long long)n*target)
                l=target;
            // set limit if the total batteries needed < target * number of computers
            else
                r=target-1;
        }
        return l;
    }
};