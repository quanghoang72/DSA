class Solution {
public:
    //time O(n)
    //space O(1)

    long long zeroFilledSubarray(vector<int>& a) {
            long long res=0;
    //     for(int i=0;i<a.size();i++){
    //         int l=i;
    //         while(i < a.size() && a[i]==0){
    //             i++;
    //         }
    //         long long size=i-l; //size of contiguous 0s subarray
    //         res+= (long long) size* (size+1)/2;
    //     }

    //0   = 1
    //00  = 3  (_0 and 00)        == +2  
    //000 = 6 (__0, _00, and 000) == +3
            int currentZeros=0;
            for(int i=0;i<a.size();i++){
                if(a[i]==0){
                    currentZeros++;
                    res+=currentZeros;
                }
                else currentZeros=0;
            }
             return res;
    }
};