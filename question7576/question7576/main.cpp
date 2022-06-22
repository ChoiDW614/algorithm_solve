#include <bits/stdc++.h>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(NULL);

int notVisited[1000000];
std::vector<int> graph[1000000];
int maxCount;

void BFS(std::queue<int> q)
{
	int count = 0;
	while (!q.empty())
	{
		int sizeofQueue = q.size();
		for (int i = 0; i < sizeofQueue; i++) {
			int x = q.front();
			for (int j = 0; j < graph[x].size(); j++) {
				if (notVisited[graph[x][j]] == 0) {
					q.push(graph[x][j]);
					notVisited[graph[x][j]] = 2;
				}
			}
			q.pop();
		}
		count++;
	}
	if (maxCount <= count) {
		maxCount = count;
	}
}

void Solve()
{
	int Row, Col;
	std::cin >> Col >> Row;

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			std::cin >> notVisited[i * 1000 + j];
		}
	}

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col-1; j++) {
			if (notVisited[i * 1000 + j + 1] != -1) {
				graph[i * 1000 + j + 1].push_back(i * 1000 + j);
				graph[i * 1000 + j].push_back(i * 1000 + j + 1);
			}
		}
	}

	for (int i = 0; i < Row - 1; i++) {
		for (int j = 0; j < Col; j++) {
			if (notVisited[(i + 1) * 1000 + j] != -1) {
				graph[(i + 1) * 1000 + j].push_back(i * 1000 + j);
				graph[i * 1000 + j].push_back((i + 1) * 1000 + j);
			}
		}
	}

	std::queue<int> q;
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			if (notVisited[i * 1000 + j] == 1) {
				q.push(i * 1000 + j);
			}
		}
	}

	BFS(q);

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			if (notVisited[i * 1000 + j] == 0) {
				std::cout << "-1";
				return;
			}
		}
	}

	std::cout << maxCount - 1;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}