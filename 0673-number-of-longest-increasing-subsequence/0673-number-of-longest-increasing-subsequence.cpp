class Solution {
public:
    //time O(n^2)
    //space O(n)
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> dp(n,{1,1});
        int maxsofar=0; //hold max len of LIS
        int res=0; //number of same max LIS len
        for(int i=n-1;i>=0;i--){
            int currentlen=1;
            int currentcount=1;
            for(int j=i+1;j<n;j++){
                auto [len,cnt]  = dp[j];
                if(nums[j]>nums[i]){
                    if(len+1 > currentlen){
                        currentlen=len+1;
                        currentcount=cnt;
                    }
                    else if(len+1 == currentlen)
                        currentcount+=cnt;
                }
            }
            if(maxsofar < currentlen){
                maxsofar=currentlen;
                res=currentcount;
            }
            else if(maxsofar == currentlen)
                res+=currentcount;
            dp[i]={currentlen,currentcount};
        }
        return res;
    }
};