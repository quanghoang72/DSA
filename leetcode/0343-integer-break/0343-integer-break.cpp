class Solution {
public:
    //time O(n^2)
    //space O(1)
    int integerBreak(int n) {
        vector<int> mp(n+1);
        mp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                int remain=i-j;
                mp[i]=max(mp[i],max(i-remain,mp[i-remain])*max(remain,mp[remain]));
            }
        }
        return mp[n];
    }
};