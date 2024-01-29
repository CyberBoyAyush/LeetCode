class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        int i = 1;
        while(i<=n){
            int digit = n%10;
            prod = prod * digit;
            sum = sum + digit;
            n = n/10;
        }
        int result = prod - sum;
        return result;
    }
};