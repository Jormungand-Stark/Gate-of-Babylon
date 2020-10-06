#include <iostream>
#include <cstring>
using namespace std;

int data[1003];

int find(int x){//寻找根节点
	int ans,tmp;
	ans = x;
	while(data[x]!=x){//x是根节点
		x=data[x];
	}
	while (ans != x) {//路径压缩
		tmp = data[ans];
		data[ans] = x;//数组内容直接储存根节点，不再存储父节点
		ans = tmp;
	}
	return x;//返回根节点的值
}

void add(int x, int y){
	if(find(x)!=find(y)){
		data[find(x)]=find(y);
	}
}

int main(int argc, char const *argv[]) {
	int n,m;//n元素个数，m元素连接条数
	int x,y;//x,y是两个相连的元素
	int flag;//未联通的结点数

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
		/*flag存储的是数组内容等于数组下标的情况（自己和自己联通）
		有多少，其值代表未联通的数目，全联通状态只有一个这样的情
		况——即根节点，所以要把根节点这个情况排除在外，即flag初值为-1*/

		for (int i = 1; i <= n; i++) {
			if(data[i]==i){
				flag++;//数组内容等于数组下标表示和自己联通
			}
		}
		cout << flag << endl;
	}

	return 0;
}
