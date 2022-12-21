class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        //key: prefix sum
        //map value: count appearance
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        
        //first 0 
        mp[sum] = 1;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            int diff=sum-k;
            
            //find if there is any previous presum that already exist
            //then we can remove that presum to get the target sum K
            if(mp.find(diff)!=mp.end())
                ans+=mp[diff];
            
            mp[sum]++;
        }
        return ans;
    }
};