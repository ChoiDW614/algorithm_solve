#include <bits/stdc++.h>
#define FAST_IO	ios_base::sync_with_stdio(false);	cin.tie(NULL);

using namespace std;
typedef long long ll;
#define INF 2e18

int N, S;
vector<ll> v(20), arr(20, INF);
ll cnt;

void bt(int it, int c)
{
	if (it == 0) {
		if (arr[it] == S) {
			cnt++;
		}
	}

}

void Solve()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	bt(N - 1);
	cout << cnt;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}