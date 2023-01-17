class Solution {
public:
    //time O(n*logm) m=from 1 to max lement in piles
    //space O(1)
    
    //koko can always eat from 1 upto r bana per hours 
    //binary search the speed k to satisfy the restrict H hour
    int minEatingSpeed(vector<int>& a, int h) {
        int r=*max_element(a.begin(),a.end()); //find max elememt
        int l=1;
        int res=r;
        while(l<=r){
            int k=(l+r)/2;
            long hourNeed=0;
            for(auto &i:a) hourNeed+=ceil(i*1.0/k);
            if(hourNeed>h) l=k+1;
            else{
                res=min(res,k);
                r=k-1;
            }
        }
        return res;
    }
};