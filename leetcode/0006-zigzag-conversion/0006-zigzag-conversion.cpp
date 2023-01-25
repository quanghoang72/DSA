class Solution {
public:
    string convert(string s, int n) {
        int sz=s.size();
        if(n==1 || n==sz)return s;
        
        //time O(n)
        //space O(1)

        // int r=0;
        // bool diag=1;
        // while(r<n){
        //     string temp="";
        //     if(r==0 || r==n-1){
        //         int i=r;
        //         while(i<sz){
        //             temp+=s[i];
        //             i+=2*n-2;
        //         }
        //         s.append(temp);
        //     }
        //     else{
        //         int i=r;
        //         int next=2*n-2;
        //         int local=(n-1-r)*2;
        //         while(i<sz){
        //             temp+=s[i];
        //             if(diag) {i+=local;diag^=1;}
        //             else {i+=next-local;diag^=1;}
        //         }
        //         s.append(temp);
        //     }
        //     r++;
        //     diag=1;
        // }
        // return s.substr(sz,sz);
        
        //time O(n)
        //space O(n)
        
        vector<string> v(n,"");
        for(int i=0,step=1,row=0;i<sz;i++){
            v[row]+=s[i];
            if(row==0) step=1;
            if(row==n-1) step=-1;
            row+=step;
        }
        for(auto& str:v) s.append(str);
        return s.substr(sz,sz);
    }
};