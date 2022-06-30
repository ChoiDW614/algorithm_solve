#include <bits/stdc++.h>
#define FASTIO 	ios_base::sync_with_stdio(false);	cin.tie(NULL), cout.tie(NULL);
using namespace std;
typedef long long ll;

bool check(int x, int y, int cx, int cy, int r)
{
	int rc = (cx - x) * (cx - x) + (cy - y) * (cy - y);
	if (r * r > rc) return true;
	else return false;
}

void Solve()
{
	int testCase;
	cin >> testCase;

	while (testCase--) {
		int x1, y1, x2, y2, n, cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;

		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;

			if (check(x1, y1, x, y, r) || check(x2, y2, x, y, r)) {
				if (check(x1, y1, x, y, r) && check(x2, y2, x, y, r)) {	}
				else
					cnt++;
			}
		}
		cout << cnt << '\n';
	}
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}