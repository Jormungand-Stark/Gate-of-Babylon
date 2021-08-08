#include<iostream>
#include<string>
using namespace std;

struct List
{
	int val;
	List* next;

	List() :val(0), next(nullptr) {}
	List(int val) :val(val), next(nullptr) {}

};
int main() {
	string s;
	int n, flag = 1;
	List *head = new List();
	List *pre = new List();

	getline(cin, s);
	cin >> n;

	while (s.find(',') != -1) { // 构建链表
		int num = s.find(',');
		string stmp = s.substr(0, num);
		List* cur = new List(stoi(stmp));
		if (flag) {
			head = cur;
			pre = head;
			flag--;
		}
		else {
			pre->next = cur;
			pre = cur;
		}
		s = s.substr(num + 1);
	}
	pre->next = new List(stoi(s));

	// 左旋
	List* first = head;
	List* second = head;
	while (n--) {
		second = second->next;
	}

	while (second->next) {
		first = first->next;
		second = second->next;
	}

	second->next = head;
	head = first->next;
	first->next = nullptr;
	
	while (head->next) {
		cout << head->val << ",";
		head = head->next;
	}
	cout << head->val;

	return 0;
}
