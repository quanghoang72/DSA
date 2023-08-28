/*
 Given an integer array nums & an integer n, return number of ways to break the chocolate into multiple parts 
 so that each part would contain exactly one nut.
 Ex. nums = [0,1,0]. return 1
     nums = [1,0,1,0,1]. return 4
 Intuition: 
    If there is no '1' in chocolate bar, return 0. Cant divide the bar into any pieces that contains Nut

    The total of '1' appearance are the number of pieces/breaks that we need
    For both end Nuts position find out how many gaps between them
    Gaps between two Nuts are also number of ways that we can break to seperate pieces with exactly one Nut.
*/
#include <bits/stdc++.h>
using namespace std;

//time O(n)
//space O(1)


long long solve(vector<int> &choco,int n){
    long long res=1;
    int start=-1;
    int end=-1;
    for(int i=0;i<choco.size();i++){
        //define starting nut position
        if(choco[i] && start==-1){
            start=i;
        }

        //find the new nut position for next piece
        else if(choco[i] && end==-1){
            end=i;
            int gap=end-start;
            res*=gap;
            
            //reset position
            start=end;
            end=-1;
        }
    }
    return res;
}
int main()
{
        int n;cin >> n;
        vector<int> v(n);
        int nutExist=0;
        for(int j=0;j<n;j++){
            int temp;cin >> temp;
            v[j]=temp;
            nutExist+=temp;
        }
        if(!nutExist) cout << 0;
        else cout << solve(v,n) << endl;
}