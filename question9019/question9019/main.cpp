#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;

vector<pair<int, char>> graph[10000];
bool visited[10000];
vector<char> cmd[10000];

void dfs(int startnode)
{
	queue<int> q;
	q.push(startnode);
	visited[startnode] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i].first;
			if (!visited[y]) {
				cmd[y] = cmd[x];
				cmd[y].push_back(graph[x][i].second);
				q.push(y);
				visited[y] = true;
			}
			else if (cmd[x].size() + 1 < cmd[y].size()) {
				cmd[y] = cmd[x];
				cmd[y].push_back(graph[x][i].second);
				q.push(y);
			}
		}
	}
}

void Solve()
{
	graph[0].push_back({ 9999, 'S'});
	for (int i = 1; i < 1000; i++) {
		graph[i].push_back({ 2 * i, 'D' });
		graph[i].push_back({ i - 1, 'S' });
		string str = to_string(i);
		while (str.size() < 4) {
			str = "0" + str;
		}
		graph[i].push_back({ (str[1] - 48) * 1000 + (str[2] - 48) * 100 + (str[3] - 48) * 10 + (str[0] - 48), 'L' });
		graph[i].push_back({ (str[3] - 48) * 1000 + (str[0] - 48) * 100 + (str[1] - 48) * 10 + (str[2] - 48), 'R' });
	}
	for (int i = 1000; i < 5000; i++) {
		graph[i].push_back({ 2 * i, 'D' });
		graph[i].push_back({ i - 1, 'S' });
		string str = to_string(i);
		graph[i].push_back({ (str[1] - 48) * 1000 + (str[2] - 48) * 100 + (str[3] - 48) * 10 + (str[0] - 48), 'L' });
		graph[i].push_back({ (str[3] - 48) * 1000 + (str[0] - 48) * 100 + (str[1] - 48) * 10 + (str[2] - 48), 'R' });
	}
	for (int i = 5000; i < 10000; i++) {
		graph[i].push_back({ 2 * (i - 5000), 'D' });
		graph[i].push_back({ i - 1, 'S' });
		string str = to_string(i);
		graph[i].push_back({ (str[1] - 48) * 1000 + (str[2] - 48) * 100 + (str[3] - 48) * 10 + (str[0] - 48), 'L' });
		graph[i].push_back({ (str[3] - 48) * 1000 + (str[0] - 48) * 100 + (str[1] - 48) * 10 + (str[2] - 48), 'R' });
	}

	int testcase;
	cin >> testcase;

	while (testcase--) {
		int A, B;
		cin >> A >> B;

		dfs(A);

		for (int i = 0; i < cmd[B].size(); i++) {
			cout << cmd[B][i];
		}
		cout << '\n';

		for (int i = 0; i < 10000; i++) {
			cmd[i].clear();
			visited[i] = false;
		}
	}
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}