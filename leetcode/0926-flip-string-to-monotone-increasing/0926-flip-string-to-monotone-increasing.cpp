class Solution {
public:
    //time O(n)
    //space O(1)

    //flips counts 0's which come after 1's, never exceeds number of 1's. 
    //if number of 0's coming after 1's is greater than the number of already seen 1's then 
    //it would be cheaper to flip all previously seen 1's down to 0 instead.
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int res=0;
        int count=0; //count number of 1s bit
        for(int i=0;i<n;i++){
            if(s[i]=='1') count++;
            else res++;
            res=min(res,count);
        }
        return res;
    }
};