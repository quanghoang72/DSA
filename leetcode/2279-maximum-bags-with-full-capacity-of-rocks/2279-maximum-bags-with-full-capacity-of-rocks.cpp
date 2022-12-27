class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        
        int n=rocks.size();
        if(n<1) return 0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(capacity[i],rocks[i]));
        }
        sort(v.begin(),v.end(),[](const auto &a, const auto &b){
            return (a.first-a.second) < (b.first-b.second);
        });
        for(auto i: v){
            cout << i.first << "  " << i.second <<  endl;
        }
        int res=0;
        for(int i=0;i<n;i++){
            int diff= v[i].first-v[i].second;
            if(diff>0 && add >= diff) {
                v[i].second+=diff;
                add-=diff;
            }
        }
        for(auto i : v) {
            if(i.first==i.second) res++;
        }
        return res;
    }
};