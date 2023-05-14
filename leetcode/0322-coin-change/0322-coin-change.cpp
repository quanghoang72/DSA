class Solution {
public:
    //m = amount ; n = number of coins
    //time O(n*m)
    //space O(m)
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]==amount+1 ? -1 : dp[amount];
    }
};