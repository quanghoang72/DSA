class Solution {
public:
    void sortColors(vector<int>& a) {
        int bucket[3]={};
        for(auto x : a ) bucket[x]++;
        int idx=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<bucket[i];j++){
                a[idx++]=i;
            }
        }
    }
};