class Solution {
public:
    //time O(n)
    //space O(n)
    int minJumps(vector<int>& a) {
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(a.size());
        for(int i=1;i<a.size();i++){
            mp[a[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0]=1;
        while(!q.empty()){
            auto [position,step]=q.front();q.pop();
            if(position == a.size()-1) return step;

            //get position of same element
            for(int i : mp[a[position]]){
                if(!visited[i]){
                    q.push({i,step+1});
                    visited[i]=1;
                }
            }
            //clear the whole vector to avoid redundant check for same value
            //avoid TLE
            mp[a[position]].clear(); 
            
            //move forward and backward
            if(position + 1 < a.size() && !visited[position+1]) {
                q.push({position+1,step+1});
                visited[position+1]=1;
            }
            if(position - 1 >= 0 && !visited[position-1]) {
                q.push({position-1,step+1});
                visited[position-1]=1;
            }

        }
        return -1;
    }
};