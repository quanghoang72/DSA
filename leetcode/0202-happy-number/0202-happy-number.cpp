class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        while(n!=1){
            if(mp[n]==0)
                mp[n]++;
            else //if encounter again = quit
                return false;
            int sum=0;
            while(n){
                sum+=pow(n%10,2);
                n/=10;
            }
            n=sum;
        }
        return true;
    }
};