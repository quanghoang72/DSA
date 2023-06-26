class Solution {
public:
    //time O(n*nlogn)
    //space O(n)
    long long totalCost(vector<int>& a, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> first;
        priority_queue<int,vector<int>,greater<int>> last;
        int n=a.size();
        int cnt=0;
        long long res=0;
        int i=0,j=n-1;
        for(cnt;cnt<k;cnt++){
            while(first.size()<candidates && i<=j) first.push(a[i++]);
            while(last.size()<candidates && i<=j) last.push(a[j--]);
            
            int f=!first.empty() ? first.top() : INT_MAX;
            int l=!last.empty() ? last.top() : INT_MAX;
            
            if(f<=l){
                first.pop();
                res+=f;
            }
            
            else{
                last.pop();
                res+=l;
            }
        }
        return res;
    }
};