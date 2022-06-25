#include <bits/stdc++.h>
#define FAST_IO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

using namespace std;

vector<int> prime;
int under_prime[100001];

void isPrime1(int N)
{
	bool exitOuter;
	prime.push_back(2);
	for (int i = 2; i <= N; i++)
	{
		exitOuter = false;
		for (int j = 0; j < prime.size(); j++) {
			if (i % prime[j] == 0) {
				exitOuter = true;
				break;
			}
		}
		if (exitOuter)
			continue;
		prime.push_back(i);
	}
	return;
}

int isPrime2(int a, int b)
{
	under_prime[2] = 1;
	under_prime[3] = 1;
	int cnt = 0;

	for (int i = 4; i <= b; i++)
	{
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				under_prime[i] = under_prime[i/j] + 1;
				break;
			}
		}
		if (!under_prime[i]) {
			under_prime[i] = 1;
		}
	}
	
	for (int i = a; i <= b; i++) {
		if (under_prime[i] != 1)
		{
			for (int j = 0; j < prime.size(); j++) {
				if (under_prime[i] == prime[j]) {
					cnt++;
					break;
				}
			}
		}
	}

	return cnt;
}

void Solve()
{
	int A, B;
	cin >> A >> B;
	isPrime1(B);
	
	cout << isPrime2(A, B);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}