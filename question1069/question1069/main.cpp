#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef long double ld;

void Solve()
{
	ld X, Y, D, T, TIME = 200000000;
	bool t = false;
	cin >> X >> Y >> D >> T;

	ld dis = sqrtl(X * X + Y * Y);
	TIME = min(TIME, dis);

	ld time = 0;
	if (dis > D)
		TIME = min(TIME, ((ll)(dis / D) + 1) * T);
	else
		TIME = min(TIME, 2 * T);

	if (dis > D) {
		time = (ll)(dis / D) * T - T;
		dis = dis - ((ll)(dis / D)) * D + D;
	}

	if (dis >= 2 * T && (fabsl(dis - D) + T >= 2 * T)) {
		time += 2 * T;
		TIME = min(TIME, time);
		t = true;
	}
	else if (dis > D) {
		time += T;
		dis -= D;
	}

	if (fabsl(dis - D) < dis && !t) {
		time += T;
		dis = fabsl(dis - D);
	}
	if (!t)
		TIME = min(TIME, time + dis);

	cout << TIME;
	return;
}

int main()
{
	FASTIO;
	cout << setprecision(20);
	Solve();
	return 0;
}