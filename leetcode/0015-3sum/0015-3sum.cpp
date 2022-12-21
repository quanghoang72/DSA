class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>res;
        sort(begin(a),end(a));

        for(int i=0;i<n-2;i++){
            if(i!=0 && a[i]==a[i-1]) continue; // same with last iteration
            int front=i+1;
            int back=n-1;
            
            while(front < back){
                int sum=a[i]+a[front]+a[back];
                if(sum==0){
                    vector<int> trip={a[i],a[front],a[back]};
                    res.push_back(trip);
                    //remove duplicate from front and back
                    while(front<back-1 && a[front]==a[front+1]) front++;
                    while(front<back-1 && a[back]==a[back-1]) back--;
                    front++;back--;              
                    //one more operation to be at the next distinct num
                }
                else if(sum < 0){
                    front++;
                }
                else back--;
            }
        }
        return res;
    }
};