#include<iostream>
using namespace std;

void sort(int* a,int len) {//插入排序，升序排列
  int temp,i,j;
  for(i = 1; i < len; i++){//决定第i个元素
    temp = a[i];
    for(j = i; 0 < j; j--){//执行i-1遍比较
      if(temp < a[j-1]){
        a[j] = a[j-1];
      }
      else{
        break;
      }
    }
    a[j] = temp;
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
