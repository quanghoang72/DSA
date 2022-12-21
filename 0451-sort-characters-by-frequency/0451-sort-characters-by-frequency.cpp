class Solution {
public:
    bool cmp(const pair <int,int>&a,const pair <int,int>&b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
       //couting and sort
    //     int cnt[128]={};
    //     for(char c : s) cnt[c]++;
    //     sort(s.begin(),s.end(), [&](char a,char b){
    //         return cnt[a] > cnt[b] || (cnt[a]==cnt[b]&& a<b);
    //     });
    //     return s;
        
    //counting and sort distinct 62(lower,upper,digit) characters 
//         unordered_map<char,int> mp;
//         for(char c : s) mp[c]++;
        
//         vector<pair <int,char>> v;
//         for(auto &[c,freq]:mp){
//             v.push_back(make_pair(freq,c));
//         }

//         sort(v.begin(), v.end(), [](const auto &a, const auto &b){
//             return a.first>b.first;
//         });
        
//         string res;
//         for(auto &[freq,c] : v)
//              res.append(freq,c); //append (char * freq)
//         return res;
        
    //bucket sort
        int n=s.size();
        unordered_map <char,int> mp;
        for(char c: s) mp[c]++;
        vector<vector<char>>bucket(n+1);
        for(auto [c,f] : mp){
            bucket[f].push_back(c);
        }
        string res;
        for(int freq=n;freq>=1;freq--){
            for(char c : bucket[freq]){
                res.append(freq,c);
            }
        }
        return res;
    }
};