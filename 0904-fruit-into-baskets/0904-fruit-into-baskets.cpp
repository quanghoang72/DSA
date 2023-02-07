class Solution {
public:
    //time O(n)
    //space O(n)
    int totalFruit(vector<int>& a) {
        int n=a.size();
        if(n<=2) return n;
        unordered_map<int,int>mp;
        int l=0;
        int res=0;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            while(mp.size()>2){
                int number=a[l];
                mp[number]--;
                if(mp[number]==0)mp.erase(number);
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};