#include <bits/stdc++.h>
#define FAST_IO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

using namespace std;
typedef long long ll;

int arr[4000001];
vector<int> prime1, prime2;

void getPrime(int N)
{
	for (int i = 2; i <= N; i++) {
		if (!arr[i]) {
			for (int j = i + i; j <= N; j += i)
				arr[j] = 1;
		}
	}
	for (int i = 2; i <= N; i++) {
		if (!arr[i]) prime1.push_back(i);
		if (!arr[i]) prime2.push_back(i);
	}
	return;
}

void Solve()
{
	int N;
	cin >> N;
	getPrime(N);

	ll cnt = 0, sum = 0;
	while (!prime1.empty()) {
		sum += prime1.back();
		prime1.pop_back();
		if (sum == N)
			cnt++;
		else if (sum > N) {
			sum -= prime2.back();
			prime2.pop_back();
		}
	}

	cout << cnt;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}