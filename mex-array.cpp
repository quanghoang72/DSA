/*
    Find the lexicographically smallest output array which can be obtained
    Mex of an array refers to the smallest missing non-negative interger of the array

    time: O(nlogn)
    space: O(1)
*/
class Solution{
	public:
	vector<int> mexArray(int n,int a[])
	{
		//code here
		sort(a,a+n);
		vector<int> res;
		int missing=1;
		int cnt=0;
		for(int i=0;i<n;i++){
		    if(a[i]==0) cnt++;
		    else{
		        res.push_back(0);
		        if(a[i]==missing) missing++;
		    }
		}
		while(cnt--){
		    res.push_back(missing);
		}
		return res;
	}
};