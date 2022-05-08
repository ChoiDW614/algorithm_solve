#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)

std::vector<int> vertex[101];
bool visited[101];
int cnt;

void BFS(int node)
{
	std::queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int now = q.front();
		for (int i = 0; i < vertex[now].size(); i++) {
			int next = vertex[now][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				cnt++;
			}
		}
		q.pop();
	}
	std::cout << cnt << '\n';
}

void Solve()
{
	int com, edgenum, from, to;
	std::cin >> com >> edgenum;
	while (edgenum--) {
		std::cin >> from >> to;
		vertex[from].push_back(to);
		vertex[to].push_back(from);
	}
	BFS(1);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}