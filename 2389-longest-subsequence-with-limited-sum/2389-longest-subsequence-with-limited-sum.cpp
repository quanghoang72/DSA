class Solution {
public:
    //time O(mlogn + n)
    //space O(n)
    vector<int> answerQueries(vector<int>& a, vector<int>& queries) {
        int m=queries.size();
        int n=a.size();
        
        sort(a.begin(), a.end());

        for (int i = 1; i < a.size(); i++){
            //prefix
            a[i] += a[i - 1];
        }
        //built in function
        vector<int> res;
        for(int i=0;i<m;i++){
            res.push_back(upper_bound(a.begin(),a.end(),queries[i])-a.begin());
        }
        
        //non built in function
        // vector<int> res(m);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(a[j]<=queries[i]) res[i]=j+1;
        //         else break;
        //     }
        // }
        return res;
    }
};
