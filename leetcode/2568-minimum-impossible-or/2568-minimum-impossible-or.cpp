class Solution {
public:
    
    int minImpossibleOR(vector<int>& a) {
        vector<bool> v(31);
        int temp=0;
        for(int i=0;i<a.size();i++){
            if(log2(a[i])==(int)log2(a[i])){
                v[log2(a[i])]=1;
            }
        }
        for(int i=0;i<31;i++){
            if(v[i]==0) return 1<<i;
        }
        return -1;
    }
};