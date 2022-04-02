#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<int> st;
int num;

void push(int x) {
	st.push(x);
	num += 1;
}

void pop() {
	if (num) {
		cout << st.top() << '\n';
		st.pop();
		num -= 1;
		return;
	}
	cout << "-1" << '\n';
	return;
}

void size() {
	cout << st.size() << '\n';
}

void empty() {
	cout << (int)st.empty() << '\n';
}

void top() {
	if (num) {
		cout << st.top() << '\n';
		return;
	}
	cout << "-1" << '\n';
	return;
}

void Solution()
{
	int N, X;
	string command;
	cin >> N;
	num = 0;
	while (N--) {
		cin >> command;
		if (command == "push") {
			cin >> X;
			push(X);
		}
		else if (command == "pop") {
			pop();
		}
		else if (command == "size") {
			size();
		}
		else if (command == "empty") {
			empty();
		}
		else if (command == "top") {
			top();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	Solution();
	return 0;
}