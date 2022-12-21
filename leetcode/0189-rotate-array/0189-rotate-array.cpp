class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        if(k%n==0) return;
        k%=n;
        int start=0;int mid=(n-k)%n; int end=n;
        int next=mid;
        while(start!=next){
            swap(a[start++],a[next++]);
            if(next==end) next=mid;
            else if(start==mid) mid=next;
        }
    }
};