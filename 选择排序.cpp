#include<iostream>
using namespace std;

void sort(int* a,int len) {//ѡ��������������
  int min,i,j;
  for(i = 0; i < len-1; i++){//ȷ�������±�Ϊi��Ԫ��
    min = a[i];//min��Ϊ��ʱ�����洢��ǰ��С��ֵ
    for(j = i+1; j < len; j++){//ִ��n-i-1��Ƚ�
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
