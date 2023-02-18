class Solution {
public:
    int minimizeSum(vector<int>& a) {
        int n=a.size();
        if(n==3) return 0;
        sort(a.begin(),a.end());
        int max_front=a[n-1]-a[2];
        int max_back=a[n-3]-a[0];
        int max_middle=a[n-2]-a[1];
        return min({max_front,max_back,max_middle});
    }
};