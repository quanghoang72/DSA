class Solution {
public:
    //time  O(n)
    //space O(1)
    int maxConsecutiveAnswers(string a, int k) {
        int n=a.size();
        int l=0,r=0;
        int res=0;
        int cntT=0,cntF=0; //count T and F freq
        for(int r=0;r<n;r++){
            a[r]=='T' ? cntT++ : cntF++; 

            //invalid window: the current window need more operations to become consecutive T/F
            while( (r-l+1) - max(cntT,cntF) - k > 0 ){
                a[l]=='T' ? cntT-- : cntF--;
                l++;
            }
            
            res=max(res,r-l+1);
        }       
        return res;
    }
};
