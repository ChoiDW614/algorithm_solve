#include <iostream>
#include <queue>
#include <vector>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);

bool notVisited[2500];
std::vector<int> graph[2500];

void BFS(int node)
{
	std::queue<int> q;
	q.push(node);
	notVisited[node] = false;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			if (notVisited[graph[x][i]]) {
				q.push(graph[x][i]);
				notVisited[graph[x][i]] = false;
			}
		}
	}
}

void clean() {
	for (int i = 0; i < 2500; i++)	notVisited[i] = false;
}

void Solve()
{
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 49; j++) {
			graph[i * 50 + j].push_back(i * 50 + j + 1);
			graph[i * 50 + j + 1].push_back(i * 50 + j);
		}
	}
	for (int i = 0; i < 49; i++) {
		for (int j = 0; j < 50; j++) {
			graph[i * 50 + j].push_back((i + 1) * 50 + j);
			graph[(i + 1) * 50 + j].push_back(i * 50 + j);
		}
	}

	int testcase;
	std::cin >> testcase;
	while (testcase--) {
		int Row, Col, cabbage, n, m, cnt = 0;
		std::cin >> Col >> Row >> cabbage;
		while (cabbage--) {
			std::cin >> n >> m;
			notVisited[m*50+n] = true;
		}
		for (int i = 0; i <= (Row - 1) * 50 + Col - 1; i++) {
			if (notVisited[i] == true) {
				BFS(i);
				cnt++;
			}
		}
		std::cout << cnt << '\n';
		clean();
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}