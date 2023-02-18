class NumArray {
public:
    NumArray(vector<int>& a) {
        v=vector<int>(a.size()+1,0);
        partial_sum(a.begin(),a.end(),v.begin()+1); //accumulate prefix subarray assign to new array at index 1
    }
    
    int sumRange(int left, int right) {
        //desire range= accumulate sum to right position minus-the prefix sum subarray position before left
        return v[right+1] - v[left];
    }
private:
    vector<int> v;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * 
 int param_1 = obj->sumRange(left,right);
 */
