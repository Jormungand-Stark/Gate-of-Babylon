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
string name;//��������
int time;//��������ʱ��
int num;//����������
char s;//����״̬
node(string name, int time = 0, int num = 0, char s = '0') :
name(name), time(time), num(num), s(s)
{
}

//���캯��
friend ostream& operator<<(ostream& o, const node& a)
//���������ʹcout����ֱ�Ӵ�ӡһ������
{
	o << " PCB_name: " << a.name << ",  time:   " << a.time
	<< ",  ������:  " << a.num << ",  ״̬:  " << a.s << endl;
	return o;
}

bool operator<(const node& a) const;/*����������������¶������ȶ���
                                      �����ȼ�*/
void run();//ģ���������
};

void print(priority_queue<node> qt);//��ӡ�����еĽ���

int main(void)
{
	priority_queue<node> q;//����һ�����ȶ���

	for (int i = 0; i < 5; i++) {//����5�����̲��������
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
	cout << "����ǰ����״̬��" << endl;
	print(q);//��ӡ���еĳ�ʼ���
	while (!q.empty()) {//�����в�Ϊ������ȡ����
		node a = q.top();//���ض��׵Ľ���
		cout << "��ѡ�еĽ���:" << a.name << endl;//��ӡ��õ��ȵĽ�������
		a.run();//���н���
		q.pop();//���ý��̵�������
		if (a.time != 0)//������û��ִ�����������
			q.push(a);
		cout << "��ʱ�Ķ���״̬:" << endl;
		print(q);//��ӡ��ʱ���е�״̬
		if (a.time == 0) {//�������ִ��������ı����״̬����ӡ
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
