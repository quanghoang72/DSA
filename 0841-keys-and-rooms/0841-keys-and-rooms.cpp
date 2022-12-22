class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s; //visited
        queue <int> q; // bfs
        q.push(0);
        s.insert(0);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i : rooms[cur]){
                if(s.count(i)==0){
                    s.insert(i);
                    q.push(i);
                }
            }
        }
        return s.size()==rooms.size();
    }
};