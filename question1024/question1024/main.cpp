#include <iostream>
#include <algorithm>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);	cin.tie(nullptr);
typedef long long ll;

void solve()
{
	ll total, len, i, init = -1;
	std::cin >> total >> len;
	
	for (i = len; i < 101; i++) {
		if ((total - (i * i - i) / 2) % i == 0 && (total - (i * i - i) / 2) / i>= 0) {
			init = (total - (i * i - i) / 2) / i;
			break;
		}
	}
	if (init == -1) {
		cout << "-1";
		return;
	}
	else {
		for (ll j = 0; j < i; j++) {
			cout << init + j << " ";
		}
	}
}

int main()
{
	FAST_IO;
	solve();
	return 0;
}