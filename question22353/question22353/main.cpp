#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);	cin.tie(NULL);

using namespace std;

void Solve()
{
	int count = 1;
	vector<pair<double, double>> winRate;
	double a, d, k, curWR, in_d;
	cin >> a >> d >> k;
	d *= 0.01; k *= 0.01;
	curWR = d;
	winRate.push_back({ a, d });
	d = 1 - curWR;

	while (curWR < 1) {
		count++;
		curWR = curWR * (1 + k);
		if (curWR > 1) { curWR = 1; }
		winRate.push_back({ a * count, d * curWR });
		d = d * (1 - curWR);
	}

	double time = 0;
	while (!winRate.empty()) {
		time += winRate.back().first * winRate.back().second;
		winRate.pop_back();
	}

	cout << time;
}

int main()
{
	FAST_IO;
	cout.precision(10);
	Solve();
	return 0;
}