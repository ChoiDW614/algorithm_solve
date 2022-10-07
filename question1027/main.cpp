#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;
typedef long long ll;

int n;
const double INF = 1987654321;
vector<double> height(50);
vector<int> sight(50);

void Solve()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> height[i];

	for (ll i = 0; i < n; i++) {
		double grad = -INF;
		for (ll j = i + 1; j < n; j++) {
			if (grad < (height[j] - height[i]) / static_cast<double>((j - i))) {
				sight[i]++;
				sight[j]++;
				grad = (height[j] - height[i]) / static_cast<double>((j - i));
			}
		}
	}

	sort(sight.begin(), sight.end(), greater<int>());
	cout << sight[0];
	return;
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}