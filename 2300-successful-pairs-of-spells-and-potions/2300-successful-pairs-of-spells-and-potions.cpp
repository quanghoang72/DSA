class Solution {
public:
    //time O(mlogm + nlogm)
    //space O(1)
    vector<int> successfulPairs(vector<int>& spell, vector<int>& pot, long long k) {
        sort(pot.begin(),pot.end());
        int i=0;
        int count=0;
        for(;i<spell.size();i++){
            int l=0;
            int r=pot.size()-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if((long long) pot[m]*spell[i]>=k) r=m-1;
                else l=m+1;
            }
            spell[i]= l== pot.size() ? 0 : pot.size()-l;
        }
        return spell;
    }
};