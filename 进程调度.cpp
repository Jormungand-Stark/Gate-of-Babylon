#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctype.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
typedef long long LL;
using namespace std;

class node {
public:
string name;//进程名称
int time;//进程运行时间
int num;//进程优先数
char s;//进程状态
node(string name, int time = 0, int num = 0, char s = '0') :
name(name), time(time), num(num), s(s)
{
}

//构造函数
friend ostream& operator<<(ostream& o, const node& a)
//运算符重载使cout可以直接打印一个对象
{
	o << " PCB_name: " << a.name << ",  time:   " << a.time
	<< ",  优先数:  " << a.num << ",  状态:  " << a.s << endl;
	return o;
}

bool operator<(const node& a) const;/*运算符重载用来重新定义优先队列
                                      的优先级*/
void run();//模拟进程运行
};

void print(priority_queue<node> qt);//打印队列中的进程

int main(void)
{
	priority_queue<node> q;//创建一个优先队列

	for (int i = 0; i < 5; i++) {//创建5个进程并且入队列
		string name = "";
		cout << "Name: "  << endl;
		cin >> name;
		int pro = 0, time = 0;
		cout << "time: " << endl;
		cin >> time;
		cout << "priority: " << endl;
		cin >> pro;
		node a(name, time, pro, 'R');
		q.push(a);
	}
	cout << "运行前队列状态：" << endl;
	print(q);//打印队列的初始情况
	while (!q.empty()) {//若队列不为空则则取队首
		node a = q.top();//返回队首的进程
		cout << "被选中的进程:" << a.name << endl;//打印获得调度的进程名称
		a.run();//运行进程
		q.pop();//将该进程弹出队首
		if (a.time != 0)//若进程没有执行完则入队列
			q.push(a);
		cout << "此时的队列状态:" << endl;
		print(q);//打印此时队列的状态
		if (a.time == 0) {//如果进程执行完了则改变进程状态并打印
			a.s = 'E';
			cout << a;
		}
	}
	return 0;
}
bool node::operator<(const node& a) const
{
	return num < a.num;
}
void node::run()
{
	time--;
	if (num > 0)
		num--;
}
void print(priority_queue<node> qt)
{
	while (!qt.empty()) {
		cout << qt.top();
		qt.pop();
	}
}
