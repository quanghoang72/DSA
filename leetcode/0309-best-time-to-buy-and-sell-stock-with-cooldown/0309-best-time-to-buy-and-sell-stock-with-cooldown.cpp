class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        if(n<2) return 0;
        int res=0;
        //store the max profit when buy at day i
        vector<int> buy(n,0);
        //store the max profit when sell at day i
        vector<int> sell(n,0);
        
        //assume that buy on day one
        buy[0]=-a[0];
        
        for(int i=1;i<n;i++){
            //buy[i-1]+a[i] = buy yesterday and sell today
            //sell[i-1]-sell[i-1]+a[i] = compute profit if we dont sell on day i-1 anymore (minus back the price)
            //and sell on today. In other word,keep the stock till today to sell it
            sell[i]=max(buy[i-1]+a[i],sell[i-1]-a[i-1]+a[i]);
            if(res<sell[i])
                res=sell[i];//update maxprofit;
            
            if(i==1)
                buy[i]=buy[0]+a[0]-a[i]; //if we didnt buy anything on first day and buy today
            else
                //cooldown 1 day
                //if we didnt buy on i-1 day but buy today
                buy[i]=max(sell[i-2]-a[i],buy[i-1]+a[i-1]-a[i]);
        }
        
        return res;
    }
};