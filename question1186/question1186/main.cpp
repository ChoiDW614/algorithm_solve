#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
typedef long long ll;
using namespace std;

pair<ll, int> cnt[51];
vector<int> v[20001];

bool cmp(const pair<ll, int>& p1, const pair<ll, int>& p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first > p2.first;
}

bool cmp2(const pair<ll, int>& p1, const pair<ll, int>& p2)
{
	return p1.second < p2.second;
}

void Solve()
{
	map<pair<ll, ll>, int> mp;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (ll j = x1; j < x2; j++)
			for (ll k = y1; k < y2; k++)
				mp[{k, j}] = i;	

		cnt[i].second = i;
	}

	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		cnt[iter->second].first++;
	}
	sort(cnt, cnt + N + 1, cmp);
	sort(cnt, cnt + K, cmp2);
	
	for (int i = 0; i < K; i++)
		cout << cnt[i].second << ' ';
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}