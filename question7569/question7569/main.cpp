#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
typedef tuple<int, int, int> coordi;

int dr[6] = { -1, 0, 1, 0, 0, 0 };
int dc[6] = { 0, 1, 0, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };
int tomato[102][102][102];

int BFS(std::queue<coordi> q)
{
	int x, y, z;
	int count = 0;
	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			x = get<0>(q.front()), y = get<1>(q.front()), z = get<2>(q.front());
			for (int j = 0; j < 6; j++)
			{
				if (tomato[x + dr[j]][y + dc[j]][z + dh[j]] == 2) {
					q.push({ x + dr[j], y + dc[j], z + dh[j] });
					tomato[x + dr[j]][y + dc[j]][z + dh[j]] = 1;
				}
			}
			q.pop();
		}
		count++;
	}
	return count;
}

void Solve()
{
	int Col, Row, Hei, count, input;
	cin >> Col >> Row >> Hei;
	std::queue<coordi> q;

	for (int i = 1; i <= Hei; i++) {
		for (int j = 1; j <= Row; j++) {
			for (int k = 1; k <= Col; k++) {
				cin >> input;
				tomato[i][j][k] = (2 - input);
				//cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					q.push({ i, j, k });
				}
			}
		}
	}
	
	count = BFS(q);

	for (int i = 1; i <= Hei; i++) {
		for (int j = 1; j <= Row; j++) {
			for (int k = 1; k <= Col; k++) {
				if (tomato[i][j][k] == 2) {
					cout << "-1";
					return;
				}
			}
		}
	}

	cout << count - 1;
	return;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}