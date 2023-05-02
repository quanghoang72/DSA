class DSU{
    vector<int> par;
    vector<int> size;
    public:
    DSU(int n){
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        size.resize(n,1);
    }
    int Find(int x){
        if(x==par[x])
            return x;
        return par[x]=Find(par[x]);
    }
    bool Union(int x,int y){
        int px=Find(x);
        int py=Find(y);
        
        if(px==py) return 0; 
        
        if(size[px] > size[py]){
            size[px]+=size[py];
            par[py]=px;
        }
        else{
            size[py]+=size[px];
            par[px]=py;
        }
        return 1;
    }
    
};
class Solution {
public:
    //time O(N^2*M)
    //space O(N)
    int numSimilarGroups(vector<string>& a) {
        int n=a.size();
        int res=n;
        DSU uf(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(a[i],a[j]) && uf.Union(i,j)){
                    res--;
                }
            }
        }
        return res;
    }
    bool isSimilar(string x,string  y){
        int same=2;
        for(int i=0;i<x.size();i++){
            if(x[i]!=y[i])
                same--;
            if(same<0) return false;
        }
        return true;
    }
};