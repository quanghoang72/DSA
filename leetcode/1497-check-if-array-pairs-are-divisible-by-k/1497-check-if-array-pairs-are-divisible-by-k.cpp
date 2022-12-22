class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        //a pair that divisible by k is when
        //sum of both two number module by k is equal to k
        // x     y
        //(a%k + b%k) =k;
        // if the frequency of x is different than y then it cannnot be a pair
       if(k==1) return true;
        vector<int> freq(k,0);
        //count freq of remainder
        for(int i=0;i<a.size();i++){
            freq[((a[i]%k)+k)%k]++; //+k %k to modulo negative number
        }
        
        if(freq[0]&1)return false; //should be even freq
        for(int i=1;i<k;i++){
            if(freq[i]!=freq[k-i]) return false;
        }
        return true;
    }
};