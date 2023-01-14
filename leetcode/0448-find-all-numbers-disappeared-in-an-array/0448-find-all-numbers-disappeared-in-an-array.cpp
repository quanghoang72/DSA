class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        //time O(n)
        //space O(n)
        //unordered_set<int> s(a.begin(),a.end());
        vector<int> res;
        int n=a.size();
        // for(int i=1;i<=n;i++){
        //     if(!s.count(i)) res.push_back(i);
        // }

        //time O(n)
        //space O(1)
        //convert passed number to negative number. If the number not appear then 
        //that index will be normal (postive)
        for(int i=0;i<n;i++){
            a[abs(a[i])-1]=-abs(a[abs(a[i])-1]);
        }
        for(int i=0;i<n;i++){
            if(a[i]>0) res.push_back(i+1);
        }

        return res;

    }
};
