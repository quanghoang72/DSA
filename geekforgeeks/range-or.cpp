/*
    Given an integet n. Find the bitwise OR of all integers from 1 to N

    time O(log(logn))
    space O(1)
*/
class Solution{
	public:
	int rangeOR(int n)
	{
		int near=log2(n);
		return ((1<<near)-1) | n ;
	}
};