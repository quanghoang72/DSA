class UnionFind{
private:
    vector<int> parent;
    vector<int> size;
public:
  UnionFind(int n){
      parent = vector<int>(n,-1);
      size = vector<int>(n,0);
  }
  void make_set(int v){
    if(parent[v]==-1)parent[v]=v;
    if(size[v]==0)size[v]=1;
  }
  int find(int v){
      if(v==parent[v]) //is representative
          return v;
      
      //path compression
      return parent[v]=find(parent[v]);
  }
  bool Union(int a,int b){
      a=find(a);
      b=find(b);
      if(a==b) return true; //there is a cycle
      
      //union by size
      if(size[a]<size[b])
          swap(a,b);
      parent[b]=a;
      size[a]+=size[b];
      
      return false;
  }
};
class Solution {
public:
    //time O(n)
    //space O(n)
    vector<int> findRedundantConnection(vector<vector<int>>& a) {
        int n=a.size();
        UnionFind uf(n+1);
        for(auto &e:a){
            uf.make_set(e[0]);
            uf.make_set(e[1]);
            if(uf.Union(e[0],e[1]))
                return e; 
        }
        return {-1,-1};
    }   
};
