class Solution {
public: 
    //time O(n)
    //space O(1)
    vector<int> addToArrayForm(vector<int>& a, int k) {
        if(k==0) return a;
        reverse(a.begin(),a.end());
        int i=0;
        int n=a.size();
        while(k){
            int digit=k%10;
            if(i<n) a[i]+=digit;
            else a.push_back(digit);
            
            int carry= a[i]/10;
            a[i]%=10;
            k/=10;
            k+=carry;
            i++;
        }
        reverse(a.begin(),a.end());
        return a;
    }
};