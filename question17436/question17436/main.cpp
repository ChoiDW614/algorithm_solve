#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N;
ll M, Num = 0;
vector<ll> prime, comprime;

void Combination(int n, int r)
{
	if (n == N) {
		return;
	}

	else {
		if(comprime[])

		Combination(n + 1, r);
	}


	

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	prime.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> prime[i];
	}



	cout << Num;
	return 0;
}