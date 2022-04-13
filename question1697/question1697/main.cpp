#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)
typedef long long ll;

std::vector<int> vertex[100002];
bool visited[100002];
ll cnt = 0;

void BFS(int node, int end)
{
	std::queue<int> que;
	que.push(node);
	visited[node] = true;

	while (!que.empty()) {
		ll qsize = que.size();
		for (int k = 0; k < qsize; k++) {
			int now = que.front();
			que.pop();
			if (now == end) {
				std::cout << cnt;
				return;
			}
			for (int i = 0; i < vertex[now].size(); i++) {
				int next = vertex[now][i];
				if (!visited[next]) {
					visited[next] = true;
					que.push(next);
				}
			}
		}
		cnt++;
	}
}

void Solve()
{
	int N, K;
	std::cin >> N >> K;

	vertex[0].push_back(1);
	for (int i = 1; i < 100000; i++) {
		vertex[i].push_back(i - 1);
		vertex[i].push_back(i + 1);
		if (i <= 50000)
			vertex[i].push_back(2 * i);
	}
	vertex[100000].push_back(99999);

	BFS(N, K);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}