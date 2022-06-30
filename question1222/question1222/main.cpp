#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);   cin.tie(NULL), cout.tie(NULL);
using namespace std;
typedef long long ll;

ll arr[2000001];

void Solve()
{
	ll N, x, max = 0, cnt = 0, i, j, max_input = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x;
		max_input = (max_input > x) ? max_input : x;
		for (j = 1; j * j <= x; j++) {
			if (x % j == 0) {
				arr[j]++;
				arr[x / j]++;
				if (j * j == x) {
					arr[j]--;
				}
			}
		}
	}

	for (i = 1; i <= max_input; i++) {
		if(arr[i] > 1)
			cnt = arr[i] * i;
		max = (max > cnt) ? max : cnt;
	}
	cout << max;
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}