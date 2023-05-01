class DSU{
    vector<int> parent;
    vector<int> rank;
    int component;
public:
    DSU(int n) {
        parent.resize(n);
        for(int i=1;i<n;i++) parent[i]=i;
        rank.resize(n,1);
        component=n-1;
    }
    int uFind(int x){
        if (x == parent[x]) return x;
        return parent[x] = uFind(parent[x]);
    }
    bool uUnion(int x,int y){
        int px = uFind(x), py = uFind(y);
        
        if (px == py) return false; //no more connection required
        
        if (rank[px] < rank[py]) { 
            rank[py] += rank[px];
            parent[px] = py;
        } else {
            rank[px] += rank[py];
            parent[py] = px;
        }
        component--;
        return 1;
    }
    
    //check the connected component
    bool isFully(){
        return component==1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& a) {
        DSU alice(n+1),bob(n+1);
        int edgeNeed=0;
        
        //type 3 is priority to union as it gives path to both A and B
        for(auto &edge : a){
            int type=edge[0]; int node1=edge[1]; int node2=edge[2];
            if(type==3){
                edgeNeed+= (alice.uUnion(node1,node2) | bob.uUnion(node1,node2));
            }
        }
        
        for(auto &edge : a){
            int type=edge[0]; int node1=edge[1]; int node2=edge[2];
            if(type==1){
                edgeNeed+= alice.uUnion(node1,node2);
            }
            else if(type==2){
                edgeNeed+=bob.uUnion(node1,node2);
            }
        }
        return alice.isFully() && bob.isFully() ? a.size()-edgeNeed : -1;
    }
};