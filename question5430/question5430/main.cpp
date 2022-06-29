#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;

void Drop(deque<int>& q, bool& end, bool reverse)
{
	if (q.empty()) {
		cout << "error";
		end = true;
		return;
	}
	if(!reverse)
		q.pop_back();
	else
		q.pop_front();
}

void Solve()
{
	int Testcase;
	cin >> Testcase;
	while (Testcase--)
	{
		string cmd, arr;
		int arrCnt;
		deque<int> q;
		cin >> cmd >> arrCnt >> arr;
		
		int tmp = 0, power = 0;
		while (!arr.empty()) {
			if (arr.back() == ']') {
				arr.pop_back();
			}
			else if (arr.back() == '[' || arr.back() == ',') {
				if (q.empty() && arr.back() == '[' && tmp == 0)
					break;

				q.push_back(tmp);
				tmp = 0; power = 0;
				arr.pop_back();
			}
			else {
				power++;
				tmp += (arr.back() - '0')*(int)pow(10, power - 1);
				arr.pop_back();
			}
		}

		bool end = false;
		bool reverse = false;
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'R') {
				reverse = !reverse;
			}
			else if (cmd[i] == 'D') {
				Drop(q, end, reverse);
			}
			if (end)
				break;
		}

		if (!end) {
			if (reverse) {
				cout << "[";
				while (!q.empty()) {
					cout << q.front();
					q.pop_front();
					if (!q.empty())
						cout << ',';
				}
				cout << "]";
			}
			else {
				cout << "[";
				while (!q.empty()) {
					cout << q.back();
					q.pop_back();
					if (!q.empty())
						cout << ',';
				}
				cout << "]";
			}
		}
		if(Testcase >= 1)
			cout << '\n';
	}
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}