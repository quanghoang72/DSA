class Solution {
public:
    //time O(n^3)
    //space O(n)
    void ksum(vector<int>&a,int k,int start,long long t,vector<int> &temp,vector<vector<int>> &res){
        if(k==2){ //back to twosum prob
            int r=a.size()-1;
            int l=start;
            while(l<r)
            {
                long long sum=a[l]+a[r];
                if(sum==t){
                    temp.push_back(a[l]);
                    temp.push_back(a[r]);
                    res.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    while(l+1<r && a[l]==a[l+1]) //skip duplicate
                        l++;
                    while(l+1<r && a[r]==a[r-1]) //skip duplicate
                        r--;
                    l++;r--;
                }
                else if(sum>t)
                    r--;
                else l++;
            }
            return;
        }
        for(int i=start;i<a.size()-k+1;i++){
            if(i>start && a[i]==a[i-1]) continue; //skip duplicate
            temp.push_back(a[i]);
            long long diff=t-a[i];
            ksum(a,k-1,i+1,diff,temp,res);
            temp.pop_back();
        }  
    }
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        if(a.size() < 4 ) return {};
        vector<vector<int>>res;
        sort(a.begin(),a.end());
        vector<int> temp;
        ksum(a,4,0,t,temp,res);
        return res;
    }
};