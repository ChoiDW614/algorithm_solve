#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);   cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N, M, Max_depth;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

int vertex[52][52];
vector<pair<int, int>> pre;

void dfs(int x, int y, int depth) {

	return;
}

void Solve()
{
	cin >> N >> M;
	string input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			if (input[j] == 'H')
				vertex[i][j + 1] = 0;
			else
				vertex[i][j + 1] = (int)(input[j]) - 48;
		}
	}
	dfs(1, 1, 1);

}

int main()
{
	FASTIO;
	Solve();
	return 0;
}