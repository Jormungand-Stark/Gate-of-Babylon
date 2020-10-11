#include<iostream>
using namespace std;

void sort(int* a,int len) {//选择排序，升序排列
  int min,i,j;
  for(i = 0; i < len-1; i++){//确定数组下标为i的元素
    min = a[i];//min作为临时变量存储当前最小的值
    for(j = i+1; j < len; j++){//执行n-i-1遍比较
      if(min > a[j]){
        a[i] = a[j];
        a[j] = min;
        min = a[i];
      }
    }
  }
}

int main(int argc, char const *argv[]) {
	int n;
	while (cin>>n,n) {
		int a[n];
		for(int i=0;i < n; i++){
			cin >> a[i];
		}
		int len = sizeof(a)/sizeof(a[0]);
		sort(a,len);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
  return 0;
}
