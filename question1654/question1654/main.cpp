#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void Solution()
{
	ll K, N, i, max_len, cnt, Max = 0;
	cin >> K >> N;
	vector<ll> vec(K);
	for (i = 0; i < K; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());
	ll lowerMax = 1, higherMax = vec[K-1];

	while(lowerMax <= higherMax) {
		max_len = (higherMax + lowerMax) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += vec[i] / max_len;
		}

		if (cnt < N) {
			higherMax = max_len - 1;
		}
		else {
			Max = (Max >= max_len) ? Max : max_len;
			lowerMax = max_len + 1;
		}
	}
	cout << Max;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	Solution();
	return 0;
}