#include <bits/stdc++.h>
#define FAST_IO	ios_base::sync_with_stdio(false);	cin.tie(NULL);

using namespace std;
int N, M;
vector<int> arr, check(9);

void dfs(int n, int depth)
{
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!check[i]) {
			check[i] = 1;
			arr.push_back(i);
			dfs(n + 1, depth + 1);
			arr.pop_back();
			check[i] = 0;
		}
	}
}

void Solve()
{
	cin >> N >> M;

	dfs(0, 0);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}