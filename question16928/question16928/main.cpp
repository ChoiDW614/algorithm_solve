#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;

bool visited[101];
vector<int> graph[101];

int bfs(int startnode)
{
	queue<int> q;
	q.push(startnode);
	visited[startnode] = true;
	int cnt = 0;
	while (!q.empty()) {
		int Size = q.size();
		for (int j = 0; j < Size; j++) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				int y = graph[x][i];
				if (y == 100) {
					return cnt;
				}
				if (!visited[y]) {
					q.push(y);
					visited[y] = true;
				}
			}
		}
		cnt++;
	}
	return cnt;
}

void Solve()
{
	for (int i = 1; i <= 94; i++) {
		graph[i].push_back(i + 1);
		graph[i].push_back(i + 2);
		graph[i].push_back(i + 3);
		graph[i].push_back(i + 4);
		graph[i].push_back(i + 5);
		graph[i].push_back(i + 6);
	}
	graph[95].push_back(96);
	graph[95].push_back(97);
	graph[95].push_back(98);
	graph[95].push_back(99);
	graph[95].push_back(100);

	graph[96].push_back(97);
	graph[96].push_back(98);
	graph[96].push_back(99);
	graph[96].push_back(100);

	graph[97].push_back(98);
	graph[97].push_back(99);
	graph[97].push_back(100);

	graph[98].push_back(99);
	graph[98].push_back(100);

	graph[99].push_back(100);

	int N, M, in, out;
	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		cin >> in >> out;
		graph[in].push_back(out);
	}
	cout << bfs(1);
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}