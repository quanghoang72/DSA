class Solution {
public:
    //time O(nlogn)
    //space O(n)
    int minSubArrayLen(int target, vector<int>& a) {
        int n=a.size();
        
        //prefix sum
        vector<long long> prefix(n);
        partial_sum(a.begin(),a.end(),prefix.begin());
        
        //position where the prefix is larger or equal to target
        int pos=lower_bound(prefix.begin(),prefix.end(),target)-prefix.begin();
        
        //sum cannot reach the target
        if(pos==n) 
            return 0;
        
        int res=pos+1;
        for(int i=pos;i<n;i++){
            int l=0,r=i;
            auto cur=prefix[i];
            
            while(l<r){
                int m = (l+r)/2;
                auto remain= cur-prefix[m];
                if(remain < target)
                    r=m;
                else{
                    res=min(res,i-m);
                    l=m+1;
                }
                
            }
        }
        return res;
    }
};


