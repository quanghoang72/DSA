class Solution {
public:
    //time O(n)
    //space O(1)
    int firstMissingPositive(vector<int>& a) {
        //time O(n)
        //space O(n)
        //int n=a.size();
        // vector<bool> check(n+1,false);
        // for(int i=0;i<n;i++){
        //     if(a[i]>0 && a[i] <= n)check[a[i]]=true;
        // }
        // for(int i=1;i<check.size();i++){
        //     if(!check[i]) return i;
        // }
        // return n+1;

        int n=a.size();
        for(int i=0;i<n;i++){
            //swap until the elemnt is in correct order
            while(a[i] <= n && a[i]>0 &&  a[i]!=a[a[i]-1]){
                swap(a[i],a[a[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]!=i+1) return i+1;
        }
        return n+1;
    }
};