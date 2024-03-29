/*
输入描述：

第一行包含空格分隔的两个数字 N和D(1 ≤ N ≤ 1000000; 1 ≤ D ≤ 1000000)

第二行包含N个整数（取值区间为[0, 1000000]）从小到大排列。从序列中提取所有数量为3的全组合，一个组合中 最大数-最小数 的差值必须 <= D。

输出描述：

输出满足要求的排列数量

利用滑动窗口限定组合的区间，之后固定区间末尾的元素，对剩余数进行取2的组合.

逻辑说明：

在 [j, i] 的范围里，当固定选 i 作为全排列中的一个元素，则剩下的两个元素从 [j, i) 的范围中组合（公式 C(i-j, 2) ），全部计算结果相加即为最终方案数。

举例说明：

当给出的序列是 1，2，3，4，5 ；差值范围为 3 时，滑动窗口第一次为 {1，2，3} ，固定 3 ，选取 （1，2） ，组成 （1，2，3）。
滑动窗口第二次为{1，2，3，4}，固定 4 ，和前三个元素进行组合，可以组合成 （1，2，4）（1，3，4）（2，3，4）。
滑动窗口第三次为{2，3，4，5}，之所以将 1 剔除是因为 5-1>3 超出差值范围，固定 5 ，和前三个元素组合，可以组合成（2，3，5）（2，4，5）（3，4，5）
因此方案数共计：1+3+3=7
*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long n, d;
    cin >> n >> d;
    vector<int> ivec(n);
    long long count = 0;
    for(int i = 0, j = 0; i < n; i++){ // i、j确定滑动窗口大小
        cin >> ivec[i];
        while(i>1 && ivec[i]-ivec[j] > d){ // 确定滑动窗口大小
            j++; // i>1时，滑动窗口里面的元素大于3个，此时要求max-min>d
        }
        count += (long long)(i-j)*(i-j-1)/2; // C(i-j, 2)公式
        // 本题的重点，等于固定 i 位，在 [j, i) 的范围内组合两个数和 i 位的数成一组
    }
    cout << count%99997867 << endl;
    return 0;
}
