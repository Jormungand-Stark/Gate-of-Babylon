#include <iostream>
using namespace std;

void sort(int* a,int len){
	int temp;
	for(size_t i = len; 0 < i; i--){//Ã°ÅÝÅÅÐò
		for(size_t j = 0; j < i; j++){
			if(a[j+1] < a[j]){
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
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

}
