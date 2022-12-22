class Solution {
public:
    int calculate(string s) {
        stack<int> nums,sym;
        long long number=0;
        int total=0;
        int sign=1;
        for(char c:s){
            if(isdigit(c)){
                number=number*10+ c-'0';
            }
            else{
                total+=number*sign;
                number=0;
                if(c=='+') sign=1;
                if(c=='-') sign=-1;
                if(c=='(') {
                    // save current sum and current sign at right before ( opertation into stack
                    // reset total and sym for calculation inside next ()
                    nums.push(total);
                    sym.push(sign);
                    total=0;
                    sign=1;
                }
                if(c==')'){
                    //compute the current round bracket then add to the previous sum/sign= top of the stack
                    total=total * sym.top() + nums.top();
                    cout << total << endl;
                    sym.pop();nums.pop();
                }
            }
        }
        //calculate the last operation outside bracket
        total+=sign*number;
        return total;
    }
};