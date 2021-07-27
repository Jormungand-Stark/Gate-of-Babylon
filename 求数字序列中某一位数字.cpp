/*数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。*/
class Solution {
public:
    int findNthDigit(int n) {
        long long start=1, count=9, digit=1;
        while(n>count){
            n -= count;
            start *= 10;
            digit++;
            count = 9*start*digit;
        }
        int num = start+(n-1)/digit;//所在数字，start为第0个数字，因此需要n-1
        //start+n/digit-1从逻辑上说行得通，但是会出现1/2-1=-1的情况，和(1-1)/2=0大相庭径
        string s = to_string(num);
        num = s[(n-1)%digit] - '0';//所在num的哪一位，数字的首个数位为0，因此需要n-1
        return num;
    }
};
