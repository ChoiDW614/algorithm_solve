#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;
typedef long double ld;

vector<pair<ld, ld>> v;

ld cal_area(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c)
{
	ld S = ((ld)1 / 2) * fabsl((a.first * b.second + b.first * c.second + c.first * a.second)
		- (a.first * c.second + c.first * b.second + b.first * a.second));
	return S;
}

void Solve()
{
	int N;
	ld x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
	
	ld area = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				area = max(area, cal_area(v[i], v[j], v[k]));
			}
		}
	}

	cout << setprecision(15);
	cout << area;
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}