class Solution {
public:
    int rob(vector<int>& a) {
        int first=0 ,second=0;
        for(int i=0;i<a.size();i++){
            int tmp=max(first+a[i],second);
            first=second;
            second=tmp;
        }
        return second;
    }
};