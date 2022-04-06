#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll hashFunc(ll x, ll m)
{
	return ((x % m) * (x % m)) % m;
}

ll countcal(ll k)
{
	return ((k-1)*k)/2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_cnt;
	ll i, n, m, hash;
	cin >> test_cnt;

	while (test_cnt) {
		unordered_map<ll, ll> map1;
		ll cnt = 0;
		cin >> n >> m;

		for (i = 0; i < m; i++) {
			hash = hashFunc(i, m);
			map1[hash] += 1;
		}

		for (auto iter = map1.begin(); iter != map1.end(); iter++)
		{
			iter->second *= n / m;
		}

		for (i = 0; i < n % m; i++)
		{
			hash = hashFunc(i, m);
			map1[hash] += 1;
		}

		for (auto iter = map1.begin(); iter != map1.end(); iter++)
		{
			cnt += countcal(iter->second);
		}

		std::cout << cnt << '\n';
		test_cnt--;
	}

	return 0;
}