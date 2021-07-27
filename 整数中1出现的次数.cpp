class Solution {
public:
    int countDigitOne(int n) {
        long long digit = 1;
        int low = 0;
        int cur = n % 10;
        int high = n / 10;
        int sum = 0;
        while(high || cur){
            if(cur==0){
                sum += high * digit;
            }
            if(cur==1){
                sum += high*digit+low+1;
            }
            if(cur!=0 && cur!=1){
                sum += (high+1)*digit;
            }
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return sum;
    }
};
