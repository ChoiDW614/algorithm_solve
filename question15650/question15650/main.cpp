#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);	cin.tie(NULL);
using namespace std;

int N, M;
vector<int> arr(9), check(9);

void dfs(int n, int depth)
{
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == 0 && i > arr[n - 1]) {
			check[i] = 1;
			arr[n] = i;
			dfs(n + 1, depth + 1);
			arr[n] = 0;
			check[i] = 0;
		}
	}
}

void Solve()
{
	cin >> N >> M;
	dfs(1, 0);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}