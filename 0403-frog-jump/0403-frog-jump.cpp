class Solution {
public:
    unordered_map<int,int>mp;
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]!=1)
            return 0;
        if(stones.size()==2)
            return (stones[1]-stones[0])==1;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        vector<vector<int>> dp(stones.size(),vector<int>(1999,-1));
        return dfs(stones,1,1,dp);
    }
    bool dfs(vector<int> &stones,int i,int k,vector<vector<int>> &dp){
        if(i==stones.size()-1)
            return 1;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int position=stones[i];
        bool res=0;
        if(mp.count(position+(k+1)))
            res|=dfs(stones,mp[position+(k+1)],k+1,dp);
        if(k!=0 && mp.count(position+k))
            res|=dfs(stones,mp[position+k],k,dp);
        if(k-1!=0 && mp.count(position+(k-1)))
            res|=dfs(stones,mp[position+(k-1)],k-1,dp);
        dp[i][k]=res;
        return res;
    }
};