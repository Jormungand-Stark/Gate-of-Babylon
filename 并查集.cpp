#include <iostream>
#include <cstring>
using namespace std;

int data[1003];

int find(int x){//Ѱ�Ҹ��ڵ�
	int ans,tmp;
	ans = x;
	while(data[x]!=x){//x�Ǹ��ڵ�
		x=data[x];
	}
	while (ans != x) {//·��ѹ��
		tmp = data[ans];
		data[ans] = x;//��������ֱ�Ӵ�����ڵ㣬���ٴ洢���ڵ�
		ans = tmp;
	}
	return x;//���ظ��ڵ��ֵ
}

void add(int x, int y){
	if(find(x)!=find(y)){
		data[find(x)]=find(y);
	}
}

int main(int argc, char const *argv[]) {
	int n,m;//nԪ�ظ�����mԪ����������
	int x,y;//x,y������������Ԫ��
	int flag;//δ��ͨ�Ľ����

	while (cin >> n,n) {

		memset(data,0,sizeof (data));
		for (int i = 1; i <= n; i++) {
			data[i] = i;
		}

		for (cin >> m; m > 0; m--) {
			cin >> x;
			cin >> y;
			add(x,y);
		}

		flag = -1;
		/*flag�洢�����������ݵ��������±��������Լ����Լ���ͨ��
		�ж��٣���ֵ����δ��ͨ����Ŀ��ȫ��ͨ״ֻ̬��һ����������
		�����������ڵ㣬����Ҫ�Ѹ��ڵ��������ų����⣬��flag��ֵΪ-1*/

		for (int i = 1; i <= n; i++) {
			if(data[i]==i){
				flag++;//�������ݵ��������±��ʾ���Լ���ͨ
			}
		}
		cout << flag << endl;
	}

	return 0;
}
