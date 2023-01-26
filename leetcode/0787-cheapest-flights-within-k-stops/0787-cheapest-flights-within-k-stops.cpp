class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int dst, int k) {
        // if(src==dst) return 0;
        // queue<pair<int,int>> q;
        vector<vector<pair<int,int>>> v(n);
        int res=INT_MAX;
        for(int i=0;i<a.size();i++){
            v[a[i][0]].push_back({a[i][1],a[i][2]});
        }
        // q.push({src,0});
        // while(!q.empty() && k>=0 ){
        //     int sz=q.size();
        //     for(int i=0;i<sz;i++){
        //         auto x=q.front().first;
        //         auto cur=q.front().second;
        //         q.pop();
        //         for(auto &i:v[x]){
        //             int arrival=i.first;
        //             int price=i.second+cur;
        //             if(res < price) continue;
        //             if(arrival==dst) {
        //                 res=min(res,price);
        //             }
        //             q.push({arrival,price});
        //         }
        //     }
        //     k--;
        // }
        // return res==INT_MAX ? -1 : res;

        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        minHeap.push( { 0, src, 0 } ); // cost, vertex, hops
        
        vector<int> dist(n+1, INT_MAX); //to avoid TLE
        
        while( !minHeap.empty() ) {
            auto t = minHeap.top(); minHeap.pop();
            int price = t[0];
            int arrival = t[1];
            int stop = t[2];
            
            if( arrival == dst )
                return price;
            
                //Optimization to avoid TLE
                //to avoid the path which has more stops till the current node
            if(dist[arrival]<stop) continue;
                 dist[arrival]=stop;

            //if the path so far is the fewest stop but has stop more than K times 
            //and definitely not the destination despite of the least consumption-> eliminate
            if(stop > k ) continue;
            
                for( auto next : v[arrival] )
                    minHeap.push( { price+next.second, next.first, stop+1 });
        }
        return -1;
    }
};