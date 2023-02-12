/*
    Let us group integers on the number line. Let's call
    integers in the range [2^i, 2^(i+1)-1] (both ends inclusive)
    for 0 <= i <= 30 in the same group. 
    You are given an array A of N elements. In on operation you can
    select any subarray of even size such that all integers in the subarray
    belong to the same group and delete that subarray.
    After deleting join the remaining subarrays without changing their order.
    Find the minimum size of A which can be obtained after performing some operations on it.

    time: O(n)
    space: O(n)
*/
class Solution{
	public:
	int evenGrouping(int n,int a[])
	{
		for(int i=0;i<n;i++){
		    a[i]=(int)log2(a[i]);
		}
		stack <int> s;
		for(int i=0;i<n;i++){
		    if(!s.empty() && a[i]==a[s.top()]){
		        s.pop();
		        continue;
		    }
		    s.push(i);
		}
		return s.size();
	}
};